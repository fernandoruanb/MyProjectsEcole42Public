/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:49:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/12 14:26:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	clean_forks(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->philosophers)
		pthread_mutex_destroy(&philo->forks[index++]);
	free(philo->forks);
	return (1);
}