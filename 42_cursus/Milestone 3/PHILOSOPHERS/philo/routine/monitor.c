/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:00:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/13 15:29:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int      check_died(t_philo *philo)
{
	if (philo->time_last_meal == 0)
		return (0);
	gettimeofday(&(philo->time), NULL);
	philo->lost_time = philo->time.tv_sec * 1000000 + philo->time.tv_usec;
	if ((philo->lost_time - philo->time_last_meal) > philo->time_to_die)
	{
		if (philo->died == 0)
		{
			printf("Philosopher %ld is dead.\n", philo->number);
			philo->died = 1;
		}
		return (1);
	}
	return (0);
}

static void	*monitoring(void *arg)
{
	t_philo	*philo;
	int	index;

	index = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		if (index >= philo->philosophers)
			index = 0;
		if (check_died(&philo->philo_ids[index]))
			break ;
		index++;
	}
	return (NULL);
}

int	monitor(t_philo *philo)
{
	pthread_t	mon;

	if (!philo)
		return (0);
	if (pthread_create(&mon, NULL, &monitoring, (void *)&philo) != 0)
		return (0);
	if (pthread_join(mon, NULL) != 0)
		return (0);
	return (1);
}
