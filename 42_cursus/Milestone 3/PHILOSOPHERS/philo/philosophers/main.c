/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 15:19:43 by fruan-ba         ###   ########.fr       */
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
	philosophers.meals_eaten = 0;
	philosophers.time_last_meal = 0;
	show_philo_struct(&philosophers);
	if (!init_each_philo_fork(&philosophers))
		return (ft_putendl_fd_1("Failed init forks.", 2));
	if (!init_each_philo_struct(&philosophers))
		ft_putendl_fd_1("Failed to init Philosophers structs", 2);
	if (!lets_go(&philosophers))
		ft_putendl_fd_1("Philosophers didn't do anything", 2);
	clean_forks(&philosophers);
	return (clean_philo_struct(&philosophers));
}
