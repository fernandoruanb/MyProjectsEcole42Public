/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:22:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 10:10:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	index;
	int	error;
	int	value;

	index = 0;
	error = 0;
	if (str[index] == '+')
		return (ft_putendl_fd_0("You cannot put + signal.", 2));
	if (str[index] == '-')
		index++;
	if (str[index] == '\0')
		return (ft_putendl_fd_0("There is/are not numbers.", 2));
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			return (ft_putendl_fd_0("Ops! Invalid char!", 2));
		index++;
	}
	value = ft_atoi_check(str, &error);
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
