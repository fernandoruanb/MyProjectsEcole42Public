/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:20:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 12:24:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	try_eat(t_philo *ph)
{
	ph->tl_meal = get_time(ph);
	ph->m_eaten++;
	printf("%ld Philo %ld is eating\n", get_time(ph) / 1000, ph->num);
	usleep(ph->t_eat * 1000);
	pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
        pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
}
