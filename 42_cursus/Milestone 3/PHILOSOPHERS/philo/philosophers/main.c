/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 10:13:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	philosophers;

	if (argc < 6)
		return (ft_putendl_fd_1("How to use: num_philosophers,\
 die_time(ms), eat_time(ms), sleep_time(ms), number_must_eat[optional]", 2));
	if (!parse_args(argc, argv, &philosophers))
		return (ft_putendl_fd_1("Invalid arguments.", 2));
	show_philo_struct(&philosophers);
	if (!get_action(&philosophers))
		return (ft_putendl_fd_1("Philosophers crashed!!!", 2));
	return (0);
}
