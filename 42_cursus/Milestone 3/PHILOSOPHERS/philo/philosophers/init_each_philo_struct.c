/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:24:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 09:10:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_each_philo_struct(t_philo *philo)
{
	int		id;
	t_philo	*philo_ids;

	philo_ids = malloc(philo->c_ph * sizeof(t_philo));
	if (!philo_ids)
		return (0);
	id = 0;
	while (id < philo->c_ph)
	{
		philo_ids[id].num = id + 1;
		philo_ids[id].id = id;
		philo_ids[id].c_ph = philo->c_ph;
		philo_ids[id].tl_meal = philo->tl_meal;
		philo_ids[id].t_die = philo->t_die;
		philo_ids[id].t_eat = philo->t_eat;
		philo_ids[id].t_sleep = philo->t_sleep;
		philo_ids[id].me_time = philo->me_time;
		philo_ids[id].m_eaten = philo->m_eaten;
		philo_ids[id].forks = philo->forks;
		philo_ids[id].time = philo->time;
		philo_ids[id].mutex = &philo->mutex[id];
		id++;
	}
	philo->philo_ids = philo_ids;
	return (1);
}
