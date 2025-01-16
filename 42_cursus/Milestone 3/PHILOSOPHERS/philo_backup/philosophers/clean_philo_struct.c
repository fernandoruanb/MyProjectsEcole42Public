/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_philo_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:05:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	clean_philo_struct(t_philo *philo)
{
	if (philo->philo_ids)
		free(philo->philo_ids);
	philo->philo_ids = NULL;
	pthread_mutex_destroy(philo->mutex);
	free(philo->mutex);
	free(philo->flag);
	return (0);
}
