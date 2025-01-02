/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:44:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 14:51:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_arg(char *arg)
{
	int	index;

	index = 0;
	if (!(arg[index] == '-' || arg[index] >= '0'
			&& arg[index] <= '9'))
		return (0);
	index++;
	if (!(arg[index] == '-' || arg[index] >= '0'
			&& arg[index] <= '9'))
		return (0);
	index++;
	while (arg[index])
	{
		if (!(arg[index] >= '0' && arg[index] <= '9'))
			return (0);
		index++;
	}
	return (1);
}
