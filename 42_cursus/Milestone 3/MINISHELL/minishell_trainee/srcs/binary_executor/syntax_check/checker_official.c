/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:08:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/09 13:04:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	char	*new_str;
	struct stat	stat_check;
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

typedef struct s_tokens
{
	char	*value;
	int	index;
	t_id	type;
	struct s_tokens	*next;
	struct s_tokens *previous;
}	t_tokens;

typedef struct	s_tree
{
	char	*value;
	t_id	type;
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tokens	*create_token(char *value, t_id type)
{
	static int	index = 0;
	t_tokens	*new_token;

	new_token = malloc(sizeof(t_tokens));
	if (!new_token)
		return (NULL);
	index++;
	new_token->value = value;
	new_token->index = index;
	new_token->type = type;
	new_token->next = NULL;
	new_token->previous = NULL;
	return (new_token);
}

void	add_token(t_tokens **root, char *value, t_id type)
{
	t_tokens	*new_token;
	t_tokens	*last;

	new_token = create_token(value, type);
	if (!new_token)
		return ;
	if (*root == NULL)
		*root = new_token;
	else
	{
		last = *root;
		while (last->next)
			last = last->next;
		last->next = new_token;
		new_token->previous = last;
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

char	*get_token(t_id type)
{
	static char	*ids[] =
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
		return (ids[type]);
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
		ft_printf("Value: %s\nType: %s\n", root->value, get_token(root->type));
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

int	free_strs_flag(char *str1, char *str2, int flag)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
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
	while (envp[index] && (!ft_strnstr(envp[index], "PATH", 4)))
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
	data->temp = ft_strjoin(data->paths[index], "/");
	if (!data->temp)
		return ;
	data->path = ft_strjoin(data->temp, root->value);
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
	return (show_error_fd("Invalid case of heredoc, append", 0, data, 0));
}

int	extra_redirect_cases(t_tokens *root, t_utils *data)
{
	if ((root->type == REDIRECT_IN || root->type == REDIRECT_OUT || root->type == APPEND)
		&& root->next != NULL && root->next->type == FD)
		return (1);
	return (show_error_fd("Invalid case of redirects", 0, data, 0));
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

int	check_is_valid_fd(t_tokens *root, t_utils *data)
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

int	case_fd(t_tokens *root, t_utils *data)
{
	if (is_number(root, data))
		return (check_is_valid_fd(root, data));
	if (check_is_directory(root, data))
		return (show_error_fd("You put a directory as file", 0, data, 0));
	if ((data->status == 0) && (!is_number(root, data)))
		return (show_error_fd("Isolated fd", 0, data, 0));
	data->status = 2;
	if (is_number(root, data) && root->next != NULL && root->next->type == REDIRECT_IN)
		return (1);
	if (root->type == FD && root->next != NULL && root->next->type == REDIRECT_OUT)
		return (1);
	if (root->type == FD && root->previous == NULL)
	       return (show_error_fd("Isolated FD without redirect", 0, data, 0));
	else if ((root->type == FD) && (root->previous != NULL)
		&& (root->previous->type == REDIRECT_OUT
		|| root->previous->type == APPEND || root->previous->type == REDIRECT_IN))
		return (1);
	else if (root->previous != NULL && root->previous->type == ARG)
		return (1);
	return (show_error_fd("Invalid case of files", 0, data, 0));
}

int	check_invalid_things(t_tokens *root)
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
		return (show_error_fd("You forgot to put things inside brackets", 0, data, 0));
	if (root->type == BRACKET_O && root->next != NULL && root->next->type == ARG)
		return (show_error_fd("You forgot to put a CMD inside BRACKET_O", 0, data, 0));
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
	if (check_invalid_things(root))
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
	if (ft_strncmp(root->value, "$", 1) == 0)
		return (1);
	return (0);
}

int	case_builtins_quotes(t_utils *data)
{
	if (ft_strcmp(data->new_str, "cd") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "export") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "unset") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "env") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "echo") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "exit") == 0)
		return (1);
	else if (ft_strcmp(data->new_str, "clear") == 0)
		return (1);
	return (0);
}

int	is_absolute_path_quotes(t_utils *data)
{
	if (access(data->new_str, F_OK | X_OK) == 0)
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
		data->temp = ft_strjoin(data->paths[index], "/");
		if (!data->temp)
			return (0);
		data->path = ft_strjoin(data->temp, data->new_str);
		if (!data->path)
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

int	is_insider_quotes(t_tokens *root, t_utils *data)
{
	size_t	length;

	if (data->new_str)
	{
		free(data->new_str);
		data->new_str = NULL;
	}
	if (!root)
		return (0);
	length = ft_strlen(root->value);
	if ((root->value[0] == '\'' && root->value[length - 1] == '\'')
		|| (root->value[0] == '\"' && root->value[length - 1] == '\"'))
	{
		data->new_str = ft_substr(root->value, 1, length - 2);
		if (!data->new_str)
			return (0);
		if (test_all_paths(data))
			return (1);
	}
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

int	how_many_quotes(t_tokens *root, t_utils *data, int letters)
{
	if (root->value[0] == '/')
		letters--;
	if (root->value[0] == '\'' || root->value[0] == '\"')
		letters++;
	if (data->simple_quotes % 2 != 0 || data->double_quotes % 2 != 0)
		return (0);
	if (letters == (data->simple_quotes + data->double_quotes))
		return (1);
	else
		return (show_error_fd("letters != quotes", 0, data, 0));
}

int	special_check_letters_quotes(t_tokens *root, t_utils *data)
{
	int	letters;
	int	index;

	letters = 0;
	index = 0;
	while (root->value[index] != '\0')
	{
		if (ft_isalpha_special(root->value[index]))
			letters++;
		else if ((root->value[index] == '\'' || root->value[index] == '\"'))
		{
			if (root->value[index] == '\'')
				data->simple_quotes++;
			else
				data->double_quotes++;
		}
		index++;
	}
	return (how_many_quotes(root, data, letters));
}

void	create_variables_order(t_tokens *root, int *index, int *flag)
{
	*index = 0;
	*flag = 0;
	if (root->value[0] == '\'' || root->value[0] == '\"')
		*index = 1;
}

int	case_quotes_syntax(char	*quote, int marker, int *flag)
{
	static char	buffer[2];
	static int	index = 0;

	if (index > 1)
		index = 0;
	if (index == 0)
		buffer[0] = quote[marker];
	else if (index == 1)
		buffer[1] = quote[marker];
	if (index == 1 || quote[marker + 1] == '\0')
	{
		if (buffer[0] != buffer[1])
			return (0);
	}
	index++;
	*flag = 0;
	return (1);
}

int	check_order_letters_quotes(t_tokens *root, t_utils *data)
{
	int	index;
	int	flag;

	create_variables_order(root, &index, &flag);
	while (root->value[index] != '\0')
	{
		if (root->value[index - 1] == '/')
			flag = 0;
		if (ft_isalpha_special_2(root->value[index])
			&& flag == 0)
		{
			flag = 1;
			index++;
		}
		else if ((root->value[index] == '\'' || root->value[index] == '\"')
			&& flag == 1)
		{
			if (!case_quotes_syntax(root->value, index, &flag))
				return (0);
			index++;
		}
		else
			return (show_error_fd("Invalid character", 0, data, 0));
	}
	return (1);
}

int	final_check(t_utils *data)
{
	if (is_absolute_path_quotes(data) || test_all_paths(data)
		|| case_builtins_quotes(data))
		return (1);
	return (show_error_fd("Invalid thing", 0, data, 0));
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
	data->new_str = ft_strdup(buffer);
	if (!data->new_str)
		return (0);
	if (!final_check(data))
		return (0);
	return (1);
}

int	special(t_tokens *root, t_utils *data)
{
	if (data->new_str)
	{
		free(data->new_str);
		data->new_str = NULL;
	}
	data->simple_quotes = 0;
	data->double_quotes = 0;
	if (!special_check_letters_quotes(root, data))
		return (0);
	if (!check_order_letters_quotes(root, data))
		return (0);
	if (!get_check_command(root, data))
		return (0);
	return (1);
}

int	case_command(t_tokens *root, t_utils *data)
{
	if ((root->type == CMD && data->status > 1) && (exist_command(root, data)
			|| check_absolute_path(root, data)))
		return (decrement_status(data));
	else if (case_builtins(root) || is_environment(root)
			|| is_insider_quotes(root, data) || special(root, data))
	{
		data->status = 1;
		return (1);
	}
	else if (root->previous != NULL && ft_strcmp(root->previous->value, "xargs") == 0)
		return (1);
	else if (root->type == CMD && check_absolute_path(root, data))
		return (1);
	else if (root->type == CMD && root->next != NULL &&
		root->previous != NULL && root->previous->type == PIPE
		&& root->next->type == PIPE)
		return (1);
	else if (root->type == CMD && data->status == 1)
		return (show_error_fd("CMD received in ARG mode", 0, data, 0));
	else if ((root->type == CMD && exist_command(root, data))
		|| check_absolute_path(root, data))
		return (1);
	return (show_error_fd("Unknown CMD syntax", 0, data, 0));
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
	return (show_error_fd("Invalid LIMITER Case", 0, data, 0));
}

int	case_arg(t_tokens *root, t_utils *data)
{
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
	return (show_error_fd("Invalid case of args", 0, data, 0));
}

int	check_invalid_brackets_position(t_utils *data)
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

int	final_case(t_tokens *root, t_utils *data)
{
	if (root->type == REDIRECT_IN || root->type == APPEND || root->type == REDIRECT_OUT)
		data->redirects++;
	if (root->type == FD)
		data->files++;
	if (root->type == CMD)
		data->commands++;
	if (root->type == ARG)
		data->args++;
	if (root->type == PIPE)
		data->pipes++;
	if (root->type == BRACKET_C)
		data->index_bra_c = root->index;
	if (root->type == BRACKET_O)
		data->index_bra_o = root->index;
	if (root->next == NULL && data->redirects != data->files)
		return (1);
	if (root->next == NULL && data->commands == 0 && data->args > 0)
		return (show_error_fd("You put args but never a command", 1, data, 0));
	if (root->next == NULL && data->commands < data->pipes)
	       return (show_error_fd("You have so many pipes than commands.", 1, data, 0));
	if (check_invalid_brackets_position(data))
		return (show_error_fd("You inverted the position of brackets", 1, data, 0));
	return (0);
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
//		ft_printf("TOKEN PASSED: %d\n", root->index);
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
	return (1);
}

void	clean_program(t_tokens *root, t_utils *data)
{
	if (data->temp)
		free(data->temp);
	if (data->path)
		free(data->path);
	if (data->paths)
		free_splits(NULL, data->paths, NULL, NULL);
	if (data->new_str)
		free(data->new_str);
	free_tokens(root);
}

t_tree	*create_branch(t_tokens *root)
{
	t_tree	*branch;

	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->value = ft_strdup(root->value);
	if (!branch->value)
	{
		free(branch);
		return (NULL);
	}
	branch->type = root->type;
	branch->parent = NULL;
	branch->left = NULL;
	branch->right = NULL;
	return (branch);
}

void  add_branch(t_tokens *root, t_tree **tree)
{
	if ((*tree)->type == CMD && root->type == ARG)
		(*tree)->left = create_branch(root);
}

void	show_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	show_tree(tree->left);
	show_tree(tree->right);
	if (tree->parent)
		printf("%s\n", tree->parent->value);
	printf("%s\n", tree->value);
	printf("  /    \\\n");
	if (tree->left)
		printf("%s\n", tree->left->value);
	else
		printf("NULL   ");
	if (tree->right)
		printf("%s\n", tree->right->value);
	else
		printf("NULL\n");
}

void	clean_tree(t_tree **tree)
{
	if (*tree != NULL)
	{
		clean_tree(&(*tree)->left);
		clean_tree(&(*tree)->right);
		free((*tree)->value);
		free(*tree);
		*tree = NULL;
	}
}

int	ft_tree(t_tokens *root)
{
	t_tree	*tree;

	tree = create_branch(root);
	root = root->next;
	while (root)
	{
		add_branch(root, &tree);
		break ;
		root = root->next;
	}
	printf("----------------\n");
	printf("\\ BINARY TREE /\n");
	printf("----------------\n");
	show_tree(tree);
	clean_tree(&tree);
	return (1);
}

void	init_utils(t_utils *data)
{
	data->index_bra_c = -1;
	data->index_bra_o = -1;
	data->brackets_o = 0;
	data->brackets_c = 0;
	data->path = NULL;
	data->simple_quotes = 0;
	data->double_quotes = 0;
	data->paths = NULL;
	data->temp = NULL;
	data->new_str = NULL;
	data->status = 0;
	data->redirects = 0;
	data->pipes = 0;
	data->args = 0;
	data->commands = 0;
	data->files = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_utils	data;
	t_tokens	*root;

	(void)argv;
	if (argc < 1)
		return (1);
	root = NULL;
	init_utils(&data);
	root = create_token("/b\'i\'n\'/l\'s", CMD);
	if (!root)
		return (1);
	add_token(&root, "-l", ARG);
	show_tokens(root);
	if (check_syntax(root, envp, &data))
	{
		printf("OK\n");
		ft_tree(root);
	}
	else
		printf("KO\n");
	clean_program(root, &data);
	return (0);
}
