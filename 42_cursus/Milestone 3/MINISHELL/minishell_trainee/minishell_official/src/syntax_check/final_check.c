/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:42:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/10 13:33:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	final_check(t_utils *data)
{
	if (!data->paths)
		return (1);
	if (case_builtins_quotes(data) || test_all_paths(data)
		|| is_absolute_path_quotes(data))
		return (1);
	return (0);
}
