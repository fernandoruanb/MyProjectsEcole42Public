/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mortal_dead.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:51:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 21:51:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../../include/minishell.h"

void	check_mortal_dead(int pid, t_data *data, int flag)
{
	waitpid(pid, &data->utils.exec_status, WNOHANG);
	if (data->utils.exec_status == 130 || data->utils.exec_status == 131)
		data->utils.mortal_dead = 1;
	if (flag == 1)
	{
		if (data->utils.fd_backup)
			close(data->utils.fd_backup);
	}
}
