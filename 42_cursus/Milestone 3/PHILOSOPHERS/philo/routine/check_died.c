/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:03:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 16:03:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_died(t_philo *ph, int *died)
{
	static int      count = 0;

	pthread_mutex_lock(ph->mutex);
	if (ph->tl_meal == 0)
	{
		pthread_mutex_unlock(ph->mutex);
		return (0);
	}
	gettimeofday(&(ph->time), NULL);
	ph->l_time = ph->time.tv_sec * 1000000 + ph->time.tv_usec;
	if ((ph->l_time - ph->tl_meal) > ph->t_die)
	{
		*died = 1;
		if (count == 0)
		{
			printf("Philo %ld died\n", ph->num);
			count++;
		}
		pthread_mutex_unlock(ph->mutex);
		return (1);
	}
	pthread_mutex_unlock(ph->mutex);
	return (0);
}
