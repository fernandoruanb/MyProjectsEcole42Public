/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:08:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 15:23:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	try_fork_2(t_philo *ph, int *died)
{
	if (check_died(ph, died))
		return (1);
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	if (check_died(ph, died))
	{
		pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
		pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
		return (1);
	}
	else
		printf("%ld Philo %ld has taken a fork\n", get_time(ph) / 1000, ph->num);
	return (0);
}
