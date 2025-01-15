/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/15 12:27:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitoring(void *arg)
{
	t_philo	*philo;
	int		index;

	philo = (t_philo *)arg;
	index = 0;
	while (index < philo->c_ph)
	{
		philo->philo_ids[index].flag->died = 1;
		index++;
	}
	return (NULL);
}

static int	monitor(t_philo *ph)
{
	pthread_t	m;

	if (pthread_create(&m, NULL, &monitoring, (void *)ph) != 0)
		return (0);
	if (pthread_join(m, NULL) != 0)
		return (0);
	return (1);
}

static void	try_catch_fork(t_philo *ph)
{
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
	printf("%ld Philo %ld is eating\n", new_time(ph) / 1000, ph->num);
	usleep(ph->t_eat * 1000);
	pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
	pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	ph->tl_meal = get_time(ph);
	ph->m_eaten++;
	printf("%ld Philo %ld is sleeping\n", new_time(ph) / 1000, ph->num);
	usleep(ph->t_sleep * 1000);
}

static void	*p(void *arg)
{
	t_philo		*ph;
	int			count;

	ph = (t_philo *)arg;
	count = 0;
	while (count < 4)
	{
		printf("%ld Philo %ld is thinking\n", new_time(ph) / 1000, ph->num);
		if (ph->id == ph->c_ph - 1)
			pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		else
			pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
		printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
		try_catch_fork(ph);
		count++;
	}
	return (NULL);
}

int	lets_go(t_philo *ph)
{
	int			i;
	pthread_t	*t;

	i = 0;
	t = malloc(ph->c_ph * sizeof(pthread_t));
	if (!t)
		return (0);
	if (!monitor(ph))
		return (0);
	while (i < ph->c_ph)
	{
		if (pthread_create(&t[i], NULL, &p, (void *)&ph->philo_ids[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < ph->c_ph)
	{
		if (pthread_join(t[i], NULL) != 0)
			return (0);
		i++;
	}
	free(t);
	return (1);
}
