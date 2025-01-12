/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:24:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 13:23:43 by fruan-ba         ###   ########.fr       */
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
		id++;
	}
	philo->philo_ids = philo_ids;
	return (1);
}
