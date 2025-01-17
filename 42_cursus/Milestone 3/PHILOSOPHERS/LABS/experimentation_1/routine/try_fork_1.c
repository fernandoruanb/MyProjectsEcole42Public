/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:49:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 17:11:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	try_fork_1(t_philo *ph)
{
	if (die(ph))
		return ;
	pthread_mutex_lock(ph->se);
	printf("%ld Philo %ld is thinking\n", new_time(ph) / 1000, ph->num);
	pthread_mutex_unlock(ph->se);
	if ((ph->id % 2) == 0)
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	if (die(ph))
	{
		if ((ph->id % 2) == 0)
			pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		else
			pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		return ;
	}
	else
	{
		pthread_mutex_lock(ph->se);
		printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
		pthread_mutex_unlock(ph->se);
	}
	try_fork_2(ph);
}
