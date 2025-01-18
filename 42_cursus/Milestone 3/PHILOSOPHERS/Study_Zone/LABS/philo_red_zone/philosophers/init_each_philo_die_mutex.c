/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_die_mutex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 16:25:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_each_philo_die_mutex(t_philo *philo)
{
	int				index;
	int				count;
	pthread_mutex_t	*mutexes;

	index = 0;
	count = 0;
	mutexes = malloc(sizeof(pthread_mutex_t));
	if (!mutexes)
		return (0);
	philo->mutex = mutexes;
	return (1);
}
