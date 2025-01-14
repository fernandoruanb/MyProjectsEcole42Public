/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 15:41:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	try_catch_fork(t_philo *ph, int *died)
{
	if (check_died(ph, died))
		return (1);
	printf("%ld Philo %ld is thinking\n", get_time(ph) / 1000, ph->num);
	if (try_fork_1(ph, died))
		return (1);
	if (try_fork_2(ph, died))
		return (1);
	if (check_died(ph, died))
		return (1);
	printf("%ld Philo %ld is eating\n", get_time(ph) / 1000, ph->num);
	usleep(ph->t_eat * 1000);
	pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
	pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	pthread_mutex_lock(ph->mutex);
	ph->m_eaten++;
	ph->tl_meal = get_time(ph);
	pthread_mutex_unlock(ph->mutex);
	if (check_died(ph, died))
		return (1);
	printf("%ld Philo %ld is sleeping\n", get_time(ph) / 1000, ph->num);
	usleep(ph->t_sleep * 1000);
	return (0);
}

static void	*p(void *arg)
{
	t_philo	*ph;
	static int	died = 0;

	ph = (t_philo *)arg;
	while (!died)
	{
		if (try_catch_fork(ph, &died))
			break ;
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
	return (1);
}
