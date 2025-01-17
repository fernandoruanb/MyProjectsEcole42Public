/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_die_mutex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 10:03:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_global_mutex(t_philo *philo)
{
	pthread_mutex_t	*se;

	se = malloc(sizeof(pthread_mutex_t));
	if (!se)
		return (0);
	if (pthread_mutex_init(se, NULL) != 0)
		return (0);
	philo->se = se;
	return (1);
}

int	init_each_philo_die_mutex(t_philo *philo)
{
	int				index;
	int				count;
	pthread_mutex_t	*mutexes;

	index = 0;
	count = 0;
	mutexes = malloc(philo->c_ph * sizeof(pthread_mutex_t));
	if (!mutexes)
		return (0);
	while (index < philo->c_ph)
	{
		if (pthread_mutex_init(&mutexes[index], NULL) != 0)
		{
			while (count < index)
				pthread_mutex_destroy(&mutexes[count++]);
			free(mutexes);
			return (0);
		}
		index++;
	}
	philo->mutex = mutexes;
	if (!init_global_mutex(philo))
		return (0);
	return (1);
}
