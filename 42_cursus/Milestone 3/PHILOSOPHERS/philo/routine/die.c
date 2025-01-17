/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/17 10:40:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	die(t_philo *ph)
{
	int	result;

	pthread_mutex_lock(ph->se);
	result = ph->flag->died;
	pthread_mutex_unlock(ph->se);
	return (result);
}
