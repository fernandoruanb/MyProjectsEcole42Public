/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:53:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 18:15:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_data *data)
{
	char	*path;

	if (data->line[4] == '~')
		path = getenv("HOME");
	else if (data->line[4] == '-')
		path = getenv("OLDPWD");
	else
		path = data->line + 3;
	chdir(path);
}
