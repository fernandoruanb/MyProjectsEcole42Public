/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_qg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:36:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/27 13:37:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ultimate_qg(int *pipefd, t_ast **root, t_data *data, int flag)
{
	if (!permission_case(pipefd, root, data, flag))
		exit(126);
}
