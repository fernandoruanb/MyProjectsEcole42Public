/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_die_mutexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:54:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 08:37:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_die_mutexes(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->c_ph)
	{
		pthread_mutex_destroy(&philo->mutex[index]);
		index++;
	}
	free(philo->mutex);
}
