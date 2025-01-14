/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_catch_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:17:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 12:19:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	try_catch_fork(t_philo *ph)
{
	printf("%ld Philo %ld is thinking\n", get_time(ph) / 1000, ph->num);
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	printf("%ld Philo %ld has taken a fork\n", get_time(ph) / 1000, ph->num);
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	printf("%ld Philo %ld has taken a fork\n", get_time(ph) / 1000, ph->num);
}
