/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:50:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 15:43:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_other_things(t_philo *ph, int id)
{
	if (die(ph))
	{
		pthread_mutex_unlock(&ph->forks[id % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[(id + 1) % ph->c_ph]);
		return ;
	}
	pthread_mutex_lock(ph->se);
	printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
	pthread_mutex_unlock(ph->se);
	pthread_mutex_lock(ph->mutex);
	ph->tl_meal = get_time(ph);
	ph->m_eaten++;
	pthread_mutex_unlock(ph->mutex);
	if (die(ph))
	{
		pthread_mutex_unlock(&ph->forks[id % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[(id + 1) % ph->c_ph]);
		return ;
	}
	pthread_mutex_lock(ph->se);
	printf("%ld Philo %ld is eating\n", new_time(ph) / 1000, ph->num);
	pthread_mutex_unlock(ph->se);
	eat_sleep(ph, 0);
	pthread_mutex_unlock(&ph->forks[id % ph->c_ph]);
	pthread_mutex_unlock(&ph->forks[(id + 1) % ph->c_ph]);
}

void	try_fork_2(t_philo *ph)
{
	int	id;

	pthread_mutex_lock(ph->mutex);
	id = ph->id;
	pthread_mutex_unlock(ph->mutex);
	if (die(ph))
	{
		if (id == ph->c_ph - 1)
			pthread_mutex_unlock(&ph->forks[(id + 1) % ph->c_ph]);
		else
			pthread_mutex_unlock(&ph->forks[id % ph->c_ph]);
		return ;
	}
	if (id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(id + 1) % ph->c_ph]);
	if (die(ph))
	{
		pthread_mutex_unlock(&ph->forks[id % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[(id + 1) % ph->c_ph]);
		return ;
	}
	check_other_things(ph, id);
}
