/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/13 08:17:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_died(t_philo *philo, int *died)
{
	*died = 0;
	if (philo->time_last_meal == 0)
		return ;
	gettimeofday(&philo->time, NULL);
	philo->lost_time = philo->time.tv_sec * 1000000 + philo->time.tv_usec;
	if ((philo->lost_time - philo->time_last_meal) > philo->time_to_die)
	{
		printf("Philosopher %ld is died.\n", philo->number);
		*died = 1;
		return ;
	}
}

static long	get_time(t_philo *philo)
{
	gettimeofday(&philo->time, NULL);
	return (philo->time.tv_sec * 1000000 + philo->time.tv_usec);
}

static void	try_catch_fork(t_philo *philo, int died)
{
	printf("Philosopher %ld is thinking...\n", philo->number);
	if (philo->id == philo->philosophers - 1)
		pthread_mutex_lock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	else
		pthread_mutex_lock(&philo->forks[philo->id % philo->philosophers]);
	printf("Philosopher %ld has taken a fork.\n", philo->number);
	if (philo->id == philo->philosophers - 1)
		pthread_mutex_lock(&philo->forks[philo->id % philo->philosophers]);
	else
		pthread_mutex_lock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	printf("Philosopher %ld has taken a fork.\n", philo->number);
	philo->time_last_meal = get_time(philo);
	philo->meals_eaten++;
	printf("Philosopher %ld is eating...\n", philo->number);
	usleep(philo->time_to_eat * 1000);
	check_died(philo, &died);
	pthread_mutex_unlock(&philo->forks[philo->id % philo->philosophers]);
	printf("Philosopher %ld has released a fork.\n", philo->number);
	pthread_mutex_unlock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	printf("Philosopher %ld has released a fork.\n", philo->number);
	printf("Philosopher %ld is sleeping...\n", philo->number);
	usleep(philo->time_to_sleep * 1000);
	check_died(philo, &died);
	if (died == 1)
		return ;
}

static void	*p(void *arg)
{
	t_philo	*philo;
	int	died;

	philo = (t_philo *)arg;
	died = 0;
	while (1)
	{
		try_catch_fork(philo, died);
		check_died(philo, &died);
		if (died == 1)
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
