/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:52:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 16:55:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse_args(int argc, char **argv, t_philo *philosophers)
{
	int		index;
	long	capture_number;

	index = 1;
	while (index < argc)
	{
		if (!is_valid_number(argv[index]))
			return (0);
		capture_number = ft_atol(argv[index]);
		if (capture_number <= 0)
			return (0);
		if (!put_on_struct(index, capture_number, philosophers))
			return (0);
		index++;
	}
	return (1);
}