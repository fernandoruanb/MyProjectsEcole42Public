/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_die_mutex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 18:23:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_each_philo_die_mutex(t_philo *philo)
{
	int				index;
	pthread_mutex_t	*mutex;

	index = 0;
	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (0);
	pthread_mutex_init(mutex, NULL);
	philo->mutex = mutex;
	return (1);
}
