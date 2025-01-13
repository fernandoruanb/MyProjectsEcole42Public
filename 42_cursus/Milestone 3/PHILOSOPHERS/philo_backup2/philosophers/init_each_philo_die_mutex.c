/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_die_mutex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/13 10:09:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_each_philo_die_mutex(t_philo *philo)
{
	int	index;
	int	count;
	pthread_mutex_t	*mutexes;

	index = 0;
	count = 0;
	mutexes = malloc(philo->philosophers * sizeof(pthread_mutex_t));
	if (!mutexes)
		return (0);
	while (index < philo->philosophers)
	{
		if (pthread_mutex_init(&mutexes[index], NULL) != 0)
		{
			while (count < index)
				pthread_mutex_destroy(&mutexes[count++]);
			free(mutexes);
		}
		index++;
	}
	philo->mutex = mutexes;
	return (1);
}
