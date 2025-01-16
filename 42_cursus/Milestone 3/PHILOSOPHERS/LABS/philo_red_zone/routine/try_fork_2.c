/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:50:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 15:59:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	try_fork_2(t_philo *ph)
{
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	if (ph->flag->died == 1)
	{
		pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		return ;
	}
	printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
	ph->tl_meal = get_time(ph);
	ph->m_eaten++;
	if (ph->flag->died == 1)
	{
		pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		return ;
	}
	printf("%ld Philo %ld is eating\n", new_time(ph) / 1000, ph->num);
	usleep(ph->t_eat * 1000);
	pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
	pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
}
