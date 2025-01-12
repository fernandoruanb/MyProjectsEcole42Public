/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:24:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 19:32:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_each_philo_struct(t_philo *philo)
{
	int		id;
	t_philo	*philo_ids;

	philo_ids = malloc(philo->philosophers * sizeof(t_philo));
	if (!philo_ids)
		return (0);
	id = 0;
	while (id < philo->philosophers)
	{
		philo_ids[id].id = id;
		philo_ids[id].philosophers = philo->philosophers;
		philo_ids[id].time_last_meal = philo->time_last_meal;
		philo_ids[id].time_to_die = philo->time_to_die;
		philo_ids[id].time_to_eat = philo->time_to_eat;
		philo_ids[id].time_to_sleep = philo->time_to_sleep;
		philo_ids[id].must_eat_time = philo->must_eat_time;
		philo_ids[id].meals_eaten = philo->meals_eaten;
		philo_ids[id].forks = philo->forks;
		philo_ids[id].time = philo->time;
		id++;
	}
	philo->philo_ids = philo_ids;
	return (1);
}
