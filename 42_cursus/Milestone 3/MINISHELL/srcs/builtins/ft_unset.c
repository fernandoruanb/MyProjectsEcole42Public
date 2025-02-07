/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:06:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/07 11:21:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_each_thing(t_data *data)
{
	int	index;

	index = 0;
	while (data->temp_env[index] != NULL)
		printf("%s\n", data->temp_env[index++]);
	printf("A variable: %s\n", data->variable);
}

static int	create_new_envp(t_data *data, size_t len_var)
{
	static int index = 0;
	static int count = 0;

	while (data->envp[index] != NULL)
	{
		if (!ft_strnstr(data->envp[index], data->variable, len_var))
		{
			data->temp_env[count] = ft_strdup(data->envp[index]);
			if (!data->temp_env[count])
			{
				count--;
				while (count > 0)
					free(data->temp_env[count--]);
				return (0);
			}
			count++;
			index++;
		}
		else
			index++;
	}
	data->temp_env[count] = NULL;
	free_splits(NULL, data->envp, NULL, NULL);
	data->envp = data->temp_env;
	return (1);
}

int	ft_unset(t_data *data)
{
	size_t	length;
	size_t	len_var;
	int	index;

	if (!data)
		return (0);
	index = 0;
	while (data->line[index] != ' ' && data->line[index] != '\0')
		index++;
	if (data->line[index] == '$')
		index++;
	len_var = ft_strlen(data->line);
	data->variable = ft_substr(data->line, index, len_var);
	if (!data->variable)
		return (0);
	length = 0;
	index = 0;
	while (data->envp[index] != NULL)
		length++;
	data->temp_env = (char **)ft_calloc(length + 1, sizeof(char *));
	if (!data->temp_env)
		return (0);
	if (!create_new_envp(data, len_var))
		return (ft_putendl_fd_1("Error creating new envp.", 2));
	print_each_thing(data);
	data->env = 1;
	return (1);
}
