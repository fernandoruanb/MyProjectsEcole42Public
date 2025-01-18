/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 16:50:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*static void	try_sleep(t_philo *ph)
{
	if (anyone_death(ph) || has_eaten_every(ph))
	{
		pthread_mutex_unlock(ph->mutex);
		return ;
	}
	pthread_mutex_lock(ph->mutex);
	printf("%ld Philo %ld is sleeping\n", new_time(ph) / 1000, ph->num);
	pthread_mutex_unlock(ph->mutex);
	usleep(ph->t_sleep * 1000);
}

static void	*p(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (anyone_death(ph) || has_eaten_every(ph))
			break ;
		else
			try_fork_1(ph);
		if (anyone_death(ph) || has_eaten_every(ph))
			break ;
		else
			try_sleep(ph);
	}
	return (NULL);
}
*/
int	lets_go(t_philo *ph)
{
	(void)ph;
	/*int			i;
	pthread_t	*t;

	i = 0;
	t = malloc(ph->c_ph * sizeof(pthread_t));
	if (!t)
		return (0);
	while (i < ph->c_ph)
	{
		if (pthread_create(&t[i], NULL, &p, (void *)&ph->philo_ids[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < ph->c_ph)
	{
		if (pthread_join(t[i], NULL) != 0)
			return (0);
		i++;
	}
	free(t);*/
	return (1);
}
