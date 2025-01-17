/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:49:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 10:49:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_message(t_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	printf("%ld Philo %ld has taken a fork\n", new_time(ph) / 1000, ph->num);
	pthread_mutex_unlock(ph->mutex);
}

void	try_fork_1(t_philo *ph)
{
	if (die(ph))
		return ;
	pthread_mutex_lock(ph->mutex);
	printf("%ld Philo %ld is thinking\n", new_time(ph) / 1000, ph->num);
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	pthread_mutex_unlock(ph->mutex);
	if (die(ph))
	{
		pthread_mutex_lock(ph->mutex);
		if (ph->id == ph->c_ph - 1)
			pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		else
			pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		pthread_mutex_unlock(ph->mutex);
		return ;
	}
	else
		print_message(ph);
	try_fork_2(ph);
}
