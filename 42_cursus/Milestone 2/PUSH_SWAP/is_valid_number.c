/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:22:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/20 21:22:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	index;

	index = 0;
	while (str[index] == '-' || str[index] == '+')
		index++;
	if (str[index] == '\0')
		return (ft_putendl_fd_0("There is/are not numbers.", 2));
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			return (ft_putendl_fd_0("Ops! Invalid char!", 2));
		index++;
	}
	return (1);
}
