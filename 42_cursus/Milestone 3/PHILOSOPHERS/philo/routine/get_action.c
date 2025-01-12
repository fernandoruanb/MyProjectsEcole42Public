/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:36:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 10:09:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*void	*philo_routine(void *arg)
{
	printf("Philosopher %d is thinking.\n", philo->index);
	pthread_mutex_lock(&philo->mutex);
	printf("Philosopher %d has taken a fork.\n", index);
	pthread_mutex_unlock(&philo->mutex);
}*/

int	get_action(t_philo *philo)
{
	int	index;

	philo = malloc(philo->philosophers * sizeof(philo));
	if (!philo)
		return (0);
	pthread_mutex_init(&philo->mutex, NULL);
	index = 0;
	while (index < philo->philosophers)
	{
		philo[index]->id = index;
		if (pthread_create(&ths[index], NULL, &philo_routine, (void *)&philo[id]) != 0)
			return (0);
		index++;
	}
	index = 0;
	while (index < philo->philosophers)
	{
		if (phthread_join(ths[index], NULL) != 0)
			return (0);
		index++;
	}
	pthread_mutex_destroy(&philo->mutex);
	//clean_philosophers(&ths);
	return (1);
}
