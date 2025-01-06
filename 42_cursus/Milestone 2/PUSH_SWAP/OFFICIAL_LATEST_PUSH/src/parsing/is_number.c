/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:34:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 15:01:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_number(const char *str)
{
	int	index;
	int	error;

	index = 0;
	error = 0;
	if (str[index] == '+')
		return (0);
	if (str[index] == '-')
		index++;
	if (str[index] == '\0')
		return (0);
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	ft_atoi_check(str, &error);
	if (error == 1)
		return (0);
	return (1);
}

/*int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	result = is_valid_number(argv[1]);
	printf("The result is: %d\n", result);
	return (0);
}*/
