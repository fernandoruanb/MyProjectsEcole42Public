/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 20:20:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_died(t_philo *philo)
{
	if (philo->time_last_meal == 0)
		return (0);
	gettimeofday(&philo->time, NULL);
	philo->lost_time = philo->time.tv_sec * 1000000 + philo->time.tv_usec;
	if ((philo->lost_time - philo->time_last_meal) > philo->time_to_die)
		return (1);
	return (0);
}

static long	get_time(t_philo *philo)
{
	gettimeofday(&philo->time, NULL);
	return (philo->time.tv_sec * 1000000 + philo->time.tv_usec);
}

static int	try_catch_fork(t_philo *philo)
{
	printf("Philosopher %ld is thinking...\n", philo->number);
	//show_philo_struct(philo);
	if (check_died(philo))
	{
		printf("Philosopher %ld is died!\n", philo->number);
		return (1);
	}
	if (philo->id == philo->philosophers - 1)
		pthread_mutex_lock(&philo->forks[philo->id + 1 % philo->philosophers]);
	else
		pthread_mutex_lock(&philo->forks[philo->id % philo->philosophers]);
	printf("Philosopher %ld has taken a fork.\n", philo->number);
	if (philo->id == philo->philosophers - 1)
		pthread_mutex_lock(&philo->forks[philo->id % philo->philosophers]);
	else
		pthread_mutex_lock(&philo->forks[philo->id + 1 % philo->philosophers]);
	printf("Philosopher %ld has taken a fork.\n", philo->number);
	philo->time_last_meal = get_time(philo);
	printf("Philosopher %ld is eating...\n", philo->number);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->forks[philo->id % philo->philosophers]);
	pthread_mutex_unlock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	philo->meals_eaten++;
	printf("Philosopher %ld is sleeping..\n", philo->number);
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

static void	*p(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (try_catch_fork(philo))
			break ;
	}
	return ((void *)(long)1);
}

int	lets_go(t_philo *philo)
{
	int			i;
	void			*get;
	pthread_t	*t;

	i = 0;
	t = malloc(philo->philosophers * sizeof(pthread_t));
	if (!t)
		return (0);
	while (i < philo->philosophers)
	{
		if (pthread_create(&t[i], NULL, &p, (void *)&philo->philo_ids[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->philosophers)
	{
		if (pthread_join(t[i], &get) != 0)
			return (0);
		if ((int)(long)get == 1)
			return (1);
		i++;
	}
	return (1);
}
