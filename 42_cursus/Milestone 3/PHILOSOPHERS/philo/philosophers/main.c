/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/13 15:46:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	finish_problem(t_philo *philosophers)
{
	printf("Philosopher 1 is thinking...\n");
	usleep(1000);
	printf("Philosopher 1 has taken a fork.\n");
	usleep(philosophers->time_to_die * 1000);
	printf("Philosopher 1 is died.\n");
	clean_forks(philosophers);
	clean_philo_struct(philosophers);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philosophers;

	if (argc < 6)
		return (ft_putendl_fd_1("How to use: num_philosophers,\
 die_time(ms), eat_time(ms), sleep_time(ms), number_must_eat[optional]", 2));
	philosophers.args = argc - 1;
	philosophers.meals_eaten = 0;
	philosophers.number = 0;
	philosophers.died = 0;
	philosophers.time_last_meal = 0;
	if (!parse_args(argc, argv, &philosophers))
		return (ft_putendl_fd_1("Invalid arguments.", 2));
	if (!init_each_philo_fork(&philosophers))
		return (ft_putendl_fd_1("Failed init forks.", 2));
	if (!init_each_philo_die_mutex(&philosophers))
		return (ft_putendl_fd_1("Failed init die mutex.", 2));
	if (!init_each_philo_struct(&philosophers))
		ft_putendl_fd_1("Failed to init Philosophers structs", 2);
	if (philosophers.philosophers == 1)
		return (finish_problem(&philosophers));
	if (!lets_go(&philosophers))
		ft_putendl_fd_1("Philosophers didn't do anything", 2);
	clean_forks(&philosophers);
	return (clean_philo_struct(&philosophers));
}
