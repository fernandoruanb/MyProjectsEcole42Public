/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:59:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/25 18:36:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*transform_string(char *input, int *flag)
{
	char	*home;
	char	*transformation;

	home = getenv("HOME");
	transformation = ft_strjoin(home, input + 1);
	if (!transformation)
		return (NULL);
	*flag = 1;
	return (transformation);
}

static char	*locate_target(char *divine_eye)
{
	int		index;
	int		pass;
	char	*str;

	index = 0;
	pass = 0;
	while (divine_eye[index + 1] != '\0')
	{
		if (divine_eye[index] == 'c'
			&& divine_eye[index + 1] == 'd')
			pass = index;
		index++;
	}
	index = 0;
	while (divine_eye[pass + index] != '\0' && divine_eye[pass + index] != '|')
		index++;
	str = ft_substr(divine_eye, pass, pass + index);
	if (!str)
		return (NULL);
	return (str);
}

static int	check_too_many_arguments(char *divine_eye)
{
	int		index;
	char	*str;

	str = locate_target(divine_eye);
	if (!str)
		return (0);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ' '
			|| str[index] == '\t')
		{
			free(str);
			return (1);
		}
		index++;
	}
	free(str);
	return (0);
}

static void	do_flag(int flag, t_data *official)
{
	if (flag == 1)
		free(official->utils.line);
}

void	ft_cd(char *input)
{
	t_data	*official;
	int		flag;

	flag = 0;
	official = get_minishell();
	if (input == NULL)
		official->utils.line = getenv("HOME");
	else if (check_too_many_arguments(input))
	{
		official->utils.exec_status = 1;
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return ;
	}
	else if (ft_strnstr(input, "~", 1))
		official->utils.line = transform_string(input, &flag);
	else if (input && flag != 1)
		official->utils.line = input;
	if (chdir(official->utils.line) == -1)
	{
		ft_putstr_fd(" No such file or directory\n", 2);
		official->utils.exec_status = 1;
	}
	else
		official->utils.exec_status = 0;
	do_flag(flag, official);
}
