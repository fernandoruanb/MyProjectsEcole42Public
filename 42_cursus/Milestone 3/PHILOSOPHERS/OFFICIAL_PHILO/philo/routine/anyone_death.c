/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anyone_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/19 16:12:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	second_case(t_philo *ph)
{
	int	result;
	int	die;
	int	time;

	pthread_mutex_lock(ph->mutex);
	result = ph->tl_meal;
	die = ph->t_die;
	time = get_time(ph);
	pthread_mutex_unlock(ph->mutex);
	if ((time - result) >= die * 1000)
	{
		pthread_mutex_lock(ph->se);
		printf("%ld Philo %ld died\n", new_time(ph) / 1000, ph->num);
		ph->flag->died = 1;
		pthread_mutex_unlock(ph->se);
		return (1);
	}
	return (0);
}

int	anyone_death(t_philo *ph)
{
	long	result;
	long	time;
	long	die;

	pthread_mutex_lock(ph->mutex);
	time = get_time(ph);
	die = ph->t_die;
	result = ph->tl_meal;
	pthread_mutex_unlock(ph->mutex);
	if (result == 0)
	{
		if ((time - ph->clock) >= die * 1000)
		{
			pthread_mutex_lock(ph->se);
			printf("%ld Philo %ld died\n", new_time(ph) / 1000, ph->num);
			ph->flag->died = 1;
			pthread_mutex_unlock(ph->se);
			return (1);
		}
	}
	else if (second_case(ph))
		return (1);
	return (0);
}
