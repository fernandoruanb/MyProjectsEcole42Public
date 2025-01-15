/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/15 11:50:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static long	see_time(t_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	gettimeofday(&ph->time, NULL);
	pthread_mutex_unlock(ph->mutex);
	return (ph->time.tv_sec * 1000000 + ph->time.tv_usec);
}

static int	finish_problem(t_philo *philo)
{
	printf("%ld Philosopher 1 is thinking\n", see_time(philo) / 1000);
	usleep(1000);
	usleep(philo->t_die * 1000);
	printf("%ld Philosopher 1 died\n", see_time(philo) / 1000);
	clean_forks(philo);
	clean_philo_struct(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5)
		return (ft_putendl_fd_1("How to use: num_philosophers,\
 die_time(ms), eat_time(ms), sleep_time(ms), number_must_eat[optional]", 2));
	philo.args = argc - 1;
	philo.m_eaten = 0;
	philo.clock = get_time(&philo);
	philo.num = 0;
	philo.tl_meal = 0;
	if (!parse_args(argc, argv, &philo))
		return (ft_putendl_fd_1("Invalid arguments.", 2));
	if (!init_each_philo_fork(&philo))
		return (ft_putendl_fd_1("Failed init forks.", 2));
	if (!init_each_philo_die_mutex(&philo))
		return (ft_putendl_fd_1("Failed init die mutex.", 2));
	if (!init_each_philo_struct(&philo))
		ft_putendl_fd_1("Failed to init Philosophers structs", 2);
	if (philo.c_ph == 1)
		return (finish_problem(&philo));
	if (!lets_go(&philo))
		ft_putendl_fd_1("Philosophers didn't do anything", 2);
	clean_forks(&philo);
	return (clean_philo_struct(&philo));
}
