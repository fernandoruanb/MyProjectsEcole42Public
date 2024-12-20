/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:42:50 by fruan-ba       #+#    #+#             */
/*   Updated: 2024/12/19 20:42:50 by fruan-ba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "push_swap.c"

int	is_valid_number(char *str)
{
	char	**result;
	int	index;
	long	value;

	result = ft_split(str);
	if (!result)
		return (0);
	index = 0;
	while (result[index] != NULL)
	{
		value = ft_atoi(result[index]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		free(result[index]);
		index++;
	}
	free(result);
	return (1);
}
