/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/13 18:11:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int      check_died(t_philo *philo)
{
	static int	count = 0;

	pthread_mutex_lock(philo->mutex);
	if (philo->time_last_meal == 0)
	{
		pthread_mutex_unlock(philo->mutex);
		return (0);
	}
	gettimeofday(&(philo->time), NULL);
	philo->lost_time = philo->time.tv_sec * 1000000 + philo->time.tv_usec;
	if ((philo->lost_time - philo->time_last_meal) > philo->time_to_die)
	{
		if (philo->died == 0 && count == 0)
		{
			printf("Philo %ld died\n", philo->number);
			philo->died = 1;
			count++;
		}
		pthread_mutex_unlock(philo->mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

static long	get_time(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	gettimeofday(&philo->time, NULL);
	pthread_mutex_unlock(philo->mutex);
	return (philo->time.tv_sec * 1000000 + philo->time.tv_usec);
}

static void	try_catch_fork(t_philo *philo)
{
	printf("%ld Philo %ld is thinking\n", get_time(philo) / 1000,  philo->number);
	if (philo->id == philo->philosophers - 1)
		pthread_mutex_lock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	else
		pthread_mutex_lock(&philo->forks[philo->id % philo->philosophers]);
	printf("%ld Philo %ld has taken a fork\n", get_time(philo) / 1000, philo->number);
	if (philo->id == philo->philosophers - 1)
		pthread_mutex_lock(&philo->forks[philo->id % philo->philosophers]);
	else
		pthread_mutex_lock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	printf("%ld Philo %ld has taken a fork\n", get_time(philo) / 1000, philo->number);
	if (check_died(philo))
		return ;
	philo->time_last_meal = get_time(philo);
	philo->meals_eaten++;
	printf("%ld Philo %ld is eating\n", get_time(philo) / 1000, philo->number);
	usleep(philo->time_to_eat * 1000);
	if (check_died(philo))
		return ;
	pthread_mutex_unlock(&philo->forks[philo->id % philo->philosophers]);
	pthread_mutex_unlock(&philo->forks[(philo->id + 1) % philo->philosophers]);
	printf("%ld Philo %ld is sleeping\n", get_time(philo) / 1000, philo->number);
	usleep(philo->time_to_sleep * 1000);
	if (check_died(philo))
		return ;
}

static void	*p(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_died(philo))
			break ;
		pthread_mutex_lock(philo->mutex);
		if (philo->died)
		{
			pthread_mutex_unlock(philo->mutex);
			break ;
		}
		pthread_mutex_unlock(philo->mutex);
		try_catch_fork(philo);
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
