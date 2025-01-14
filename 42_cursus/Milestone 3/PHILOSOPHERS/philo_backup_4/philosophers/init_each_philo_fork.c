/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:39:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 09:09:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_each_philo_fork(t_philo *philo)
{
	int				index;
	int				count;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * philo->c_ph);
	if (!forks)
		return (0);
	index = 0;
	while (index < philo->c_ph)
	{
		if (pthread_mutex_init(&forks[index], NULL) != 0)
		{
			count = 0;
			while (count < index)
				pthread_mutex_destroy(&forks[count++]);
			free(forks);
			return (0);
		}
		index++;
	}
	philo->forks = forks;
	return (1);
}
