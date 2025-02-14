/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:08:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/14 18:51:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

typedef struct s_tree
{
	char	*value;
	int	index;
	valueuct s_tree	*left;
	valueuct s_tree	*parent;
	valueuct s_tree	*right;
}	t_tree;

typedef struct s_utils
{
	char	*temp;
	char	*path;
	char	**paths;
	int	status;
	int	redirects;
	int	files;
	int	commands;
	int	pipes;
	int	simple_quotes;
	int	double_quotes;
	int	args;
	int	brackets_c;
	int	brackets_o;
	int	index_bra_c;
	int	index_bra_o;
	char	*new_value;
	char	*copy_new;
	valueuct stat	stat_check;
}	t_utils;

typedef enum e_id
{
	PIPE,
	LIMITER,
	CMD,
	ARG,
	FD,
	BRACKET_O,
	BRACKET_C,
	REDIRECT_IN,
	REDIRECT_OUT,
	HEREDOC,
	APPEND,
	OPERATOR_OR,
	OPERATOR_AND,
}	t_id;

typedef valueuct s_tokens
{
	char	*value;
	int	index;
	t_id	type;
	struct s_tokens	*next;
	struct s_tokens *previous;
}	t_tokens;

void    check_copy_new(t_utils *data);

static int	check_file_descriptor(t_tokens *root, char *file);

t_tokens	*create_tokens(char *value, t_value type)
{
	static int	index = 0;
	t_tokens	*new_tokens;

	new_tokens = malloc(sizeof(t_tokens));
	if (!new_tokens)
		return (NULL);
	index++;
	new_tokens->value = value;
	new_tokens->index = index;
	new_tokens->type = type;
	new_tokens->next = NULL;
	new_tokens->previous = NULL;
	return (new_tokens);
}

void	add_tokens(t_tokens **root, char *value, t_value type)
{
	t_tokens	*new_tokens;
	t_tokens	*last;

	new_tokens = create_tokens(value, type);
	if (!new_tokens)
		return ;
	if (*root == NULL)
		*root = new_tokens;
	else
	{
		last = *root;
		while (last->next)
			last = last->next;
		last->next = new_tokens;
		new_tokens->previous = last;
	}
}

void	free_tokens(t_tokens *root)
{
	t_tokens	*temp;

	while (root)
	{
		temp = root->next;
		root->next = NULL;
		root->previous = NULL;
		free(root);
		root = temp;
	}
	root = NULL;
}

char	*get_tokens(t_value type)
{
	static char	*values[] =
	{
		"PIPE",
		"LIMITER",
		"CMD",
		"ARG",
		"FD",
		"BRACKET_O",
		"BRACKET_C",
		"REDIRECT_IN",
		"REDIRECT_OUT",
		"HEREDOC",
		"APPEND",
		"OPERATOR_OR",
		"OPERATOR_AND"
	};
	if (type >= 0 && type <= OPERATOR_AND)
		return (values[type]);
	else
		return (NULL);
}

void	show_tokens(t_tokens *root)
{
	int	index;

	index = 1;
	while (root)
	{
		ft_printf("TOKEN %d\n", root->index);
		ft_printf("Value: %s\nType: %s\n", root->value, get_tokens(root->type));
		if (root->next)
			ft_printf("Next: %s\n", root->next->value);
		else
			ft_printf("Next: NULL\n");
		if (root->previous)
			ft_printf("Previous: %s\n", root->previous->value);
		else
			ft_printf("Previous: NULL\n");
		root = root->next;
	}
}

int	free_types_flag(char *value1, char *value2, int flag)
{
	if (value1)
		free(value1);
	if (value2)
		free(value2);
	if (flag == 1)
		return (1);
	return (0);
}

void	show_paths(t_utils *data)
{
	int	index;

	index = 0;
	while (data->paths[index] != NULL)
		printf("%s\n", data->paths[index++]);
}

void	get_paths(char **envp, t_utils *data)
{
	int	index;

	index = 0;
	while (envp[index] && (!ft_strncmp(envp[index], "PATH", 4)))
		index++;
	data->paths = ft_split(envp[index] + 5, ':');
	if (!data->paths)
		return ;
}

void	get_full_path(t_tokens *root, int index, t_utils *data)
{
	if (data->temp)
		free(data->temp);
	if (data->path)
		free(data->path);
	data->temp = ft_ft_strjoin(data->paths[index], "/");
	if (!data->temp)
		return ;
	data->path = ft_ft_strjoin(data->temp, root->value);
}

int	check_absolute_path(t_tokens *root, t_utils *data)
{
	if (access(root->value, F_OK | X_OK) == 0)
	{
		data->status = 1;
		return (1);
	}
	return (0);
}

int	exist_command(t_tokens *root, t_utils *data)
{
	int	index;

	index = 0;
	while (data->paths[index] != NULL)
	{
		get_full_path(root, index, data);
		if (!data->path)
			return (0);
		if (access(data->path, F_OK | X_OK) == 0)
		{
			data->status = 1;
			return (1);
		}
		index++;
	}
	return (0);
}

int	free_each_split(char **split1, char **split2, int flag)
{
	int	index;

	if (split1 && *split1)
	{
		index = 0;
		while (split1[index] != NULL)
		{
			free(split1[index]);
			index++;
		}
	}
	if (split2 && *split2)
	{
		index = 0;
		while (split2[index] != NULL)
		{
			free(split2[index]);
			index++;
		}
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	show_error_fd(char *message, int flag, t_utils *data, int signal)
{
	ft_putendl_fd(message, 2);
	if (signal == 1)
		data->status++;
	if (flag == 1)
		return (1);
	return (0);
}

int	decrement_status(t_utils *data)
{
	data->status = 1;
	return (1);
}

int	case_pipe(t_tokens *root, t_utils *data)
{
	if (data->status == 0)
		return (show_error_fd("Pipe is the first to appear.", 0, data, 0));
	data->status = 2;
	if (root->next != NULL && root->next->type == BRACKET_O)
		return (1);
	if (root->next != NULL && (root->next->type == REDIRECT_OUT 
		|| root->next->type == REDIRECT_IN || root->next->type == APPEND 
		|| root->next->type == HEREDOC))
		return (1);
	if ((root->type == PIPE) && (root->previous == NULL
		|| root->next == NULL))
		return (show_error_fd("PIPE Error without next or previous", 0, data, 0));
	else if (data->status != 0 && root->next->type != CMD)
		return (show_error_fd("PIPE next elements isn't a CMD", 0, data, 0));
	return (1);
}

int	heredoc_or_append(t_tokens *root, t_utils *data)
{
	if (root->type == HEREDOC && root->next != NULL && root->next->type == LIMITER)
	{
		data->status = 2;
		return (1);
	}
	if (root->type == HEREDOC && root->previous != NULL && root->previous->type == CMD
		&& root->next != NULL && root->next->type == LIMITER)
		return (1);
	if (root->type == HEREDOC && root->previous != NULL && root->previous->type == ARG
		&& root->next != NULL && root->next->type == LIMITER)
		return (1);
	if (root->type == APPEND && root->next != NULL && (root->next->type == FD))
	{
		data->status = 2;
		return (1);
	}
	if (root->type == HEREDOC && root->next != NULL 
		&& root->next->type == LIMITER && root->previous != NULL
		&& root->previous->type == CMD)
		return (1);
	return (show_error_fd("Invalvalue case of heredoc, append", 0, data, 0));
}

int	extra_redirect_cases(t_tokens *root, t_utils *data)
{
	if ((root->type == REDIRECT_IN || root->type == REDIRECT_OUT || root->type == APPEND)
		&& root->next != NULL && root->next->type == FD)
		return (1);
	return (show_error_fd("Invalvalue case of redirects", 0, data, 0));
}

int	case_redirect(t_tokens *root, t_utils *data)
{
	if (root->type == HEREDOC || root->type == APPEND)
		return (heredoc_or_append(root, data));
	if (data->status == 0 && (root->type == REDIRECT_IN || root->type == REDIRECT_OUT
		|| root->type == APPEND) && root->next != NULL && root->next->type == FD)
	{
		data->status = 2;
		return (1);
	}
	data->status = 2;
	if (root->type == REDIRECT_IN && root->previous != NULL 
		&& root->previous->type == CMD && root->next != NULL 
		&& root->next->type == FD)
		return (1);
	if (root->type == REDIRECT_IN && root->next != NULL
		&& root->next->type == FD)
		return (1);
	if (root->type == REDIRECT_OUT && root->next == NULL)
		return (show_error_fd("Forgot a file after red_out", 0, data, 0));
	if (root->type == REDIRECT_OUT && root->next != NULL 
		&& root->next->type != FD)
		return (show_error_fd("Forgot a file after red_out", 0, data, 0));
	if (root->type == REDIRECT_OUT && root->next->type == FD)
		return (1);
	return (extra_redirect_cases(root, data));
}

int	is_number(t_tokens *root, t_utils *data)
{
	int	index;

	index = 0;
	while (root->value[index] != '\0')
	{
		if (!ft_isdigit(root->value[index]))
			return (0);
		index++;
	}
	data->files--;
	return (1);
}

int	check_is_valvalue_fd(t_tokens *root, t_utils *data)
{
	long	check_fd;

	check_fd = ft_atoi(root->value);
	if (check_fd > 2147483647)
		return (show_error_fd("Too extreme file descriptor", 0, data, 0));
	return (1);
}

int	check_is_directory(t_tokens *root, t_utils *data)
{

	if (stat(root->value, &data->stat_check) == -1)
		return (0);
	if (S_ISDIR(data->stat_check.st_mode))
		return (1);
	return (0);
}

int	invalvalue_fd(t_tokens *root)
{
	if (root->previous != NULL && root->previous->value == REDIRECT_IN)
		if (access(root->value, F_OK) != 0)
			return (1);
	return (0);
}

int	case_fd(t_tokens *root, t_utils *data)
{
	if (invalvalue_fd(root))
		return (show_error_fd("Syntax: FD Error", 0 ,data, 0));
	if (is_number(root, data))
		return (check_is_valvalue_fd(root, data));
	if (check_is_directory(root, data))
		return (show_error_fd("Syntax: FD Error", 0, data, 0));
	if ((data->status == 0) && (!is_number(root, data)))
		return (show_error_fd("Syntax: FD Error", 0, data, 0));
	data->status = 2;
	if (is_number(root, data) && root->next != NULL
		&& root->next->value == REDIRECT_IN)
		return (1);
	if (root->value == FD && root->next != NULL && root->next->value == REDIRECT_OUT)
		return (1);
	if (root->value == FD && root->previous == NULL)
		return (show_error_fd("Syntax: FD Error", 0, data, 0));
	else if ((root->value == FD) && (root->previous != NULL)
		&& (root->previous->value == REDIRECT_OUT
			|| root->previous->value == APPEND
			|| root->previous->value == REDIRECT_IN))
		return (1);
	else if (root->previous != NULL && root->previous->value == ARG)
		return (1);
	return (show_error_fd("Syntax: FD Error", 0, data, 0));
}

int	check_invalvalue_things(t_tokens *root)
{
	if ((root->type == OPERATOR_AND || root->type == OPERATOR_OR)
		&& (root->next != NULL) && (root->previous != NULL)
		&& (root->next->type == PIPE || root->previous->type == PIPE
		|| root->next->type == OPERATOR_AND || root->previous->type == OPERATOR_AND
		|| root->next->type == OPERATOR_OR || root->previous->type == OPERATOR_OR))
		return (1);
	return (0);
}

int	check_brackets(t_tokens *root, t_utils *data)
{
	if (root->type == BRACKET_C)
		data->brackets_c++;
	else if (root->type == BRACKET_O)
		data->brackets_o++;
	data->status = 2;
	if (root->type == BRACKET_O && root->next != NULL 
		&& root->next->type == BRACKET_C)
		return (show_error_fd("You forgot to put things insvaluee brackets", 0, data, 0));
	if (root->type == BRACKET_O && root->next != NULL && root->next->type == ARG)
		return (show_error_fd("You forgot to put a CMD insvaluee BRACKET_O", 0, data, 0));
	if (root->type == BRACKET_C && root->next == NULL && data->brackets_o != data->brackets_c)
		return (show_error_fd("Isolated BRACKET_C", 0, data, 0));
	return (1);
}

int	extra_cases(t_tokens *root, t_utils *data)
{
	if (root->type == BRACKET_O || root->type == BRACKET_C)
		return (check_brackets(root, data));
	if (root->next == NULL && data->brackets_o != data->brackets_c)
		return (show_error_fd("You forgot to close brackets", 0, data, 0));
	if (root->type == OPERATOR_AND && data->status == 0)
		return (show_error_fd("Operator_AND was the first", 0, data, 0));
	if (root->type == OPERATOR_OR && data->status == 0)
		return (show_error_fd("Operator_OR was the first", 0, data, 0));
	data->status = 2;
	if (check_invalvalue_things(root))
		return (show_error_fd("Operators and delimiters are joking", 0, data, 0));
	if ((root->type == OPERATOR_AND) && (root->previous == NULL
		|| root->next == NULL))
		return (show_error_fd("Operator_AND without complements", 0, data, 0));
	if ((root->type == OPERATOR_OR) && (root->previous == NULL
		|| root->next == NULL))
		return (show_error_fd("Operator_OR without complements", 0, data, 0));
	return (1);
}

int	case_builtins(t_tokens *root)
{
	if (ft_strcmp(root->value, "cd") == 0)
		return (1);
	else if (ft_strcmp(root->value, "export") == 0)
		return (1);
	else if (ft_strcmp(root->value, "unset") == 0)
		return (1);
	else if (ft_strcmp(root->value, "pwd") == 0)
		return (1);
	else if (ft_strcmp(root->value, "env") == 0)
		return (1);
	else if (ft_strcmp(root->value, "echo") == 0)
		return (1);
	else if (ft_strcmp(root->value, "exit") == 0)
		return (1);
	else if (ft_strcmp(root->value, "clear") == 0)
		return (1);
	return (0);
}

int	is_environment(t_tokens *root)
{
	if (ft_valuencmp(root->value, "$", 1) == 0)
		return (1);
	return (0);
}

int	case_builtins_quotes(t_utils *data)
{
	if (ft_strcmp(data->copy_new, "cd") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "export") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "unset") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "pwd") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "env") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "echo") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "exit") == 0)
		return (1);
	else if (ft_strcmp(data->copy_new, "clear") == 0)
		return (1);
	return (0);
}

int	is_absolute_path_quotes(t_utils *data)
{
	if (access(data->copy_new, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

int	test_all_paths(t_utils *data)
{
	int	index;
	index = 0;
	while (data->paths[index] != NULL)
	{
		if (data->temp)
			free(data->temp);
		if (data->path)
			free(data->path);
		data->temp = ft_ft_strjoin(data->paths[index], "/");
		if (!data->temp)
			return (0);
		data->path = ft_ft_strjoin(data->temp, data->copy_new);
		if (!data->path || ft_strcmp(data->path, data->temp) == 0)
			return (0);
		if (access(data->path, F_OK | X_OK) == 0)
			return (1);
		index++;
	}
	if (case_builtins_quotes(data))
		return (1);
	if (is_absolute_path_quotes(data))
		return (1);
	return (0);
}

void	check_copy_new(t_utils *data)
{
	if (data->new_value)
	{
		free(data->new_value);
		data->new_value = NULL;
	}
	if (data->copy_new)
	{
		free(data->copy_new);
		data->copy_new = NULL;
	}
}

int	is_insvalueer_quotes(t_tokens *root, t_utils *data)
{
	size_t	length;

	check_copy_new(data);
	if (!root)
		return (0);
	length = ft_valuelen(root->value);
	if ((root->value[0] == '\'' && root->value[length - 1] == '\'')
		|| (root->value[0] == '\"' && root->value[length - 1] == '\"'))
	{
		data->new_value = ft_subvalue(root->value, 1, length - 2);
		if (!data->new_value)
			return (0);
		data->copy_new = ft_valuedup(data->new_value);
		if (!data->copy_new)
			return (0);
		if (test_all_paths(data))
			return (1);
	}
	if (!data->copy_new)
		data->copy_new = ft_valuedup(root->value);
	return (0);
}

int	ft_isalpha_special(char letter)
{
	return (letter >= 'a' && letter <= 'z');
}

int	ft_isalpha_special_2(char letter)
{
	return (ft_isalpha_special(letter) || letter == '/');
}

int	check_final_quotes(t_tokens *root)
{
	int		index;
	char	quote;

	index = 0;
	while (root->value[index] != '\0')
	{
		if (root->value[index] == '\'' || root->value[index] == '\"')
		{
			quote = root->value[index];
			index++;
			while (root->value[index] != '\0' && root->value[index] != quote)
				index++;
			if (root->value[index] == '\0')
				return (0);
		}
		index++;
	}
	return (1);
}

int	how_many_quotes(t_tokens *root, t_utils *data)
{
	if (root->value == ARG && check_final_quotes(root))
		return (1);
	if (data->simple_quotes % 2 != 0 || data->double_quotes % 2 != 0)
		return (show_error_fd("Syntax: QUOTES Error", 0, data, 0));
	return (1);
}

int	special_check_quotes(t_tokens *root, t_utils *data)
{
	int	index;

	data->simple_quotes = 0;
	data->double_quotes = 0;
	index = 0;
	while (root->value[index] != '\0')
	{
		if ((root->value[index] == '\'' || root->value[index] == '\"'))
		{
			if (root->value[index] == '\'' && 
				root->value[index - 1] != '\\')
				data->simple_quotes++;
			else if (root->value[index - 1] != '\\')
				data->double_quotes++;
		}
		index++;
	}
	return (how_many_quotes(data));
}

int	final_check(t_utils *data)
{
	if (case_builtins_quotes(data) || test_all_paths(data)
		|| is_absolute_path_quotes(data))
		return (1);
	return (0);
}

int	get_check_command(t_tokens *root, t_utils *data)
{
	char	buffer[4096];
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (root->value[index] != '\0')
	{
		if (ft_isalpha_special_2(root->value[index]))
		{
			buffer[count] = root->value[index];
			count++;
		}
		index++;
	}
	buffer[count] = '\0';
	check_copy_new(data);
	data->copy_new = ft_valuedup(buffer);
	if (!data->copy_new)
		return (0);
	if (!final_check(data))
		return (ft_putendl_fd_0("Error at final check", 2));
	return (1);
}

int	check_quotes(t_tokens *root)
{
	int	index;
	char	quote;
	int	flag;

	index = 0;
	flag = 0;
	while (root->value[index] != '\0')
	{
		if ((flag == 1) && (root->value[index] == '\'' || root->value[index] == '\"'))
		{
			if (quote != root->value[index])
				return (ft_putendl_fd_0("Invalvalue quotes", 2));
			flag = 0;
		}
		else if (root->value[index] == '\'' || root->value[index] == '\"')
		{
			flag = 1;
			quote = root->value[index];
		}
		index++;
	}
	return (1);
}

int	special(t_tokens *root, t_utils *data)
{
	if (data->new_value)
	{
		free(data->new_value);
		data->new_value = NULL;
	}
	data->simple_quotes = 0;
	data->double_quotes = 0;
	if (!special_check_quotes(root, data))
		return (ft_putendl_fd_0("Special quotes Error", 2));
	if (!check_quotes(root))
		return (ft_putendl_fd_0("Error here check quotes", 2));
	if (!get_check_command(root, data))
		return (ft_putendl_fd_0("We can't check command.", 2));
	return (1);
}

static int	get_subvalue(t_tokens *root)
{
	char	*subvalue;
	int	result;

	subvalue = ft_valuedup(root->value + 2);
	if (!subvalue)
		return (0);
	result = check_file_descriptor(root, subvalue);
	free(subvalue);
	return (result);
}

static int	check_file_descriptor(t_tokens *root, char *file)
{
	t_tokens	*last;

	last = root;
	while (last->previous)
		last = last->previous;
	while (last->next)
	{
		if (ft_strcmp(last->value, file) == 0)
				return (1);
		last = last->next;
	}
	return (0);
}

static int	extra_cases_commands(t_tokens *root, t_utils *data)
{
	if ((root->value == CMD) && root->value[0] == '.' && root->value[1] == '/')
	{
		return (special_check_quotes(root, data)
			&& !check_is_directory(root, data) && get_subvalue(root));
	}
	else if ((root->value == CMD) && (exist_command(root, data)
			|| check_absolute_path(root, data)
			|| is_insvalueer_quotes(root, data) || special(root, data)))
	{
		data->status = 1;
		return (1);
	}
	return (0);
}

int	case_command(t_tokens *root, t_utils *data)
{
	if ((root->value == CMD && data->status > 1) && (exist_command(root, data)
			|| check_absolute_path(root, data)))
		return (decrement_status(data));
	else if (case_builtins(root) || is_environment(root)
		|| is_insvalueer_quotes(root, data) || special(root, data))
	{
		data->status = 1;
		return (1);
	}
	else if (root->previous != NULL
		&& ft_strcmp(root->previous->value, "xargs") == 0)
		return (1);
	else if (root->value == CMD && check_absolute_path(root, data))
		return (1);
	else if (root->value == CMD && root->next != NULL
		&& root->previous != NULL && root->previous->value == PIPE
		&& root->next->value == PIPE)
		return (1);
	else if (root->value == CMD && data->status == 1)
		return (show_error_fd("Syntax: CMD Error", 0, data, 0));
	else if (extra_cases_commands(root, data))
		return (1);
	return (show_error_fd("Syntax: CMD Error", 0, data, 0));
}

int	case_limiter(t_tokens *root, t_utils *data)
{
	if (data->status == 0)
		return (show_error_fd("LIMITER is the first to appear!", 0, data, 0));
	data->status = 2;
	if (root->type == LIMITER && root->previous != NULL && root->previous->type == HEREDOC
		&& root->next != NULL && root->next->type != LIMITER)
		return (1);
	if (root->type == LIMITER && root->previous != NULL && root->previous->type == HEREDOC
		&& root->next == NULL)
		return (1);
	return (show_error_fd("Invalvalue LIMITER Case", 0, data, 0));
}

int	case_arg(t_tokens *root, t_utils *data)
{
	if (!special_check_quotes(root, data))
		return (0);
	if (root->type == ARG && data->status == 1)
		return (1);
	else if (root->type == ARG && root->previous != NULL && (root->previous->type == FD
		|| root->previous->type == REDIRECT_OUT || root->previous->type == REDIRECT_IN
		|| root->previous->type == APPEND || root->previous->type == ARG))
		return (1);
	else if (root->type == ARG && root->next != NULL && (root->next->type == ARG
			|| root->next->type == FD))
		return (1);
	else if (root->type == ARG && root->previous != NULL && root->previous->type == LIMITER)
		return (1);
	return (show_error_fd("Invalvalue case of args", 0, data, 0));
}

int	check_invalvalue_brackets_position(t_utils *data)
{
	if (data->index_bra_o != -1 && data->index_bra_c != -1)
	{
		if (data->index_bra_o > data->index_bra_c)
			return (1);
		else
		{
			data->index_bra_o = -1;
			data->index_bra_c = -1;
		}
	}
	return (0);
}

int	extra_case_cmds(t_tokens *root)
{
	if (root->value == CMD && ft_strcmp(root->value, "./") == 0)
		return (1);
	if (root->value == CMD && !check_quotes(root))
		return (1);
	return (0);
}

int	final_case(t_tokens *root, t_utils *data)
{
	if (root->value == REDIRECT_IN || root->value == APPEND
		|| root->value == REDIRECT_OUT)
		data->redirects++;
	if (root->value == FD)
		data->files++;
	if (root->value == CMD)
		data->commands++;
	if (root->value == ARG)
		data->args++;
	if (root->value == PIPE)
		data->pipes++;
	if (root->value == BRACKET_C)
		data->index_bra_c = root->index;
	if (root->value == BRACKET_O)
		data->index_bra_o = root->index;
	if (root->next == NULL && data->redirects != data->files)
		return (1);
	if (root->next == NULL && data->commands == 0 && data->args > 0)
		return (0);
	if (root->next == NULL && data->commands < data->pipes)
		return (0);
	if (check_invalvalue_brackets_position(data))
		return (0);
	return (extra_case_cmds(root));
}

int	get_command(t_tokens *root, t_utils *data)
{
	if (final_case(root, data))
		return (show_error_fd("Final case Error", 0, data, 0));
	if (root->type == PIPE)
		return (case_pipe(root, data));
	else if (root->type == LIMITER)
		return (case_limiter(root, data));
	else if (root->type == OPERATOR_AND 
		|| root->type == OPERATOR_OR || root->type == BRACKET_O || root->type == BRACKET_C)
		return (extra_cases(root, data));
	else if (root->type == REDIRECT_IN || root->type == REDIRECT_OUT
			|| root->type == APPEND || root->type == HEREDOC)
			return (case_redirect(root, data));
	else if (root->type == FD)
		return (case_fd(root, data));
	else if (root->type == CMD)
		return (case_command(root, data));
	else if (root->type != CMD && data->status == 0)
		return (show_error_fd("The first argument isn't a CMD", 0, data, 0));
	if (root->next == NULL && data->brackets_o != data->brackets_c)
		return (show_error_fd("You forgot to close brackets", 0, data, 0));
	if (root->type == ARG)
		return (case_arg(root, data));
	return (show_error_fd("Unfortunately, we don't know what we need to do", 0, data, 0));
}

int	check_syntax(t_tokens *root, char **envp, t_utils *data)
{
	int	flag;

	get_paths(envp, data);
	if (!data->paths)
		return (0);
	flag = 1;
	while (root)
	{
		//ft_printf("TOKEN PASSED: %d\n", root->index);
		if (get_command(root, data))
			root = root->next;
		else
		{
			flag = 0;
			break ;
		}
	}
	if (flag != 1)
		return (0);
	if (data->brackets_o != data->brackets_c)
		return (show_error_fd("Brackets opened", 0, data, 0));
	return (1);
}

void	clean_program(t_tokens *root, t_utils *data)
{
	if (data->temp)
		free(data->temp);
	if (data->path)
		free(data->path);
	if (data->copy_new)
		free(data->copy_new);
	if (data->paths)
		free_splits(NULL, data->paths, NULL, NULL);
	if (data->new_value)
		free(data->new_value);
	free_tokens(root);
}

void	init_utils(t_utils *data)
{
	data->index_bra_c = -1;
	data->index_bra_o = -1;
	data->brackets_o = 0;
	data->brackets_c = 0;
	data->path = NULL;
	data->simple_quotes = 0;
	data->copy_new = NULL;
	data->double_quotes = 0;
	data->paths = NULL;
	data->temp = NULL;
	data->new_value = NULL;
	data->status = 0;
	data->redirects = 0;
	data->pipes = 0;
	data->args = 0;
	data->commands = 0;
	data->files = 0;
}

t_tree	*create_new_branch(char *value)
{
	static int	index = 0;
	t_tree	*branch;

	if (!value)
		return (NULL);
	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->value = value;
	branch->index = index++;
	branch->parent = NULL;
	branch->left = NULL;
	branch->right = NULL;
	return (branch);
}

void	clean_tree(t_tree **tree)
{
	if (*tree == NULL)
		return ;
	clean_tree(&(*tree)->left);
	clean_tree(&(*tree)->right);
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->parent = NULL;
	free(*tree);
	*tree = NULL;
}

void	show_tree(t_tree *tree, int level)
{
	int	index;

	if (!tree)
		return ;
	index = 0;
	show_tree(tree->left, level + 1);
	while (index++ < level)
		ft_printf("    ");
	ft_printf("%d %s    \n", tree->index, tree->value);
	show_tree(tree->right, level + 1);
}

int	is_operator(char *value)
{
	if (!value)
		return (0);
	if (ft_strcmp(value, "|") == 0
		|| ft_strcmp(value, ">") == 0
		|| ft_strcmp(value, "<") == 0
		|| ft_strcmp(value, ">>") == 0
		|| ft_strcmp(value, "<<") == 0
		|| ft_strcmp(value, "&&") == 0
		|| ft_strcmp(value, "||") == 0)
		return (1);
	return (0);
}

t_tokens	*find_the_last_tokens(t_tokens *root)
{
	t_tokens	*last;

	last = root;
	while (last->next)
		last = last->next;
	return (last);
}

void	add_pipe(char *value, t_tree **tree)
{
	t_tree	*last;

	last = *tree;
	while (last->left)
		last = last->left;
	last->left = create_new_branch(value);
}

void	add_tree_element(t_tree **tree, char *value)
{
	if (*tree == NULL)
		*tree = create_new_branch(value);
	if (ft_strcmp(value, "|") == 0)
		add_pipe(value, tree);
}

void	add_all_elements(t_tokens *last, t_tree **tree)
{
	if (!last)
		return ;
	if (last->previous == NULL)
		add_tree_element(tree, last->value);
	while (last->previous)
	{
		if (is_operator(last->value))
			add_tree_element(tree, last->value);
		else if (last->type == CMD)
			add_tree_element(tree, last->value);
		last = last->previous;
	}
}

void	add_new_branch(t_tokens *root, t_tree **tree)
{
	t_tokens	*last;

	last = find_the_last_tokens(root);
	add_all_elements(last, tree);
}

int	ft_tree(t_tokens *root, t_tree **tree)
{
	if (!root)
		return (0);
	add_new_branch(root, tree);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_utils	data;
	t_tokens	*root;
	t_tree		*tree;

	(void)argv;
	if (argc < 1)
		return (1);
	root = NULL;
	tree = NULL;
	init_utils(&data);
	root = create_tokens("ls", CMD);
	if (!root)
		return (1);
	show_tokens(root);
	if (check_syntax(root, envp, &data))
	{
		printf("OK\n");
		ft_tree(root, &tree);
	}
	else
		printf("KO\n");
	if (tree)
	{
		ft_printf("\n---------------------\n");
		ft_printf("-----BINARY-TREE-----\n");
		ft_printf("---------------------\n");
		ft_printf("\n");
		show_tree(tree, 1);
		clean_tree(&tree);
	}
	clean_program(root, &data);
	return (0);
}
