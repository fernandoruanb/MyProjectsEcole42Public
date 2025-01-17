/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_eaten_every.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:40:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 11:51:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	has_eaten_every(t_philo *ph)
{
	int	result;

	pthread_mutex_lock(ph->mutex);
	result = ph->m_eaten == ph->me_time;
	pthread_mutex_unlock(ph->mutex);
	return (result);
}
