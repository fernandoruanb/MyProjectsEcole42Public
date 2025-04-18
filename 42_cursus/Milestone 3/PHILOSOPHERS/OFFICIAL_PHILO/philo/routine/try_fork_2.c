/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:50:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/19 18:05:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	unlock_forks_correctly(t_philo *ph)
{
	if (ph->id % 2 == 0)
		pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	else
		pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
}

static void	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->se);
	if (!ph->flag->died)
		printf("%ld Philo %ld is eating\n", new_time(ph) / 1000, ph->num);
	ph->ate_last = ph->id;
	pthread_mutex_unlock(ph->se);
	eat_sleep(ph, 0);
	pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
}

static void	check_other_things(t_philo *ph)
{
	if (die(ph))
	{
		pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		return ;
	}
	pthread_mutex_lock(ph->se);
	if (!ph->flag->died)
		printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
	pthread_mutex_unlock(ph->se);
	pthread_mutex_lock(ph->mutex);
	ph->tl_meal = get_time(ph);
	ph->m_eaten++;
	pthread_mutex_unlock(ph->mutex);
	if (die(ph))
	{
		pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		return ;
	}
	eating(ph);
}

void	try_fork_2(t_philo *ph)
{
	if (die(ph))
	{
		if ((ph->id % 2) == 0 && ph->ate_last != ph->id)
			pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		else if (ph->ate_last != ph->id)
			pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		return ;
	}
	if ((ph->id % 2) == 0)
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	if (die(ph))
	{
		if (ph->id == ph->ate_last)
			unlock_forks_correctly(ph);
		else
		{
			pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
			pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		}
		return ;
	}
	check_other_things(ph);
}
