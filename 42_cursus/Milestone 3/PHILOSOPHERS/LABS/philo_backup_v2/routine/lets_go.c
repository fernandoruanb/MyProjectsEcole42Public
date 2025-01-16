/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/16 11:14:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitoring(void *arg)
{
	t_philo	*philo;
	int		index;
	int		count;

	philo = (t_philo *)arg;
	index = 0;
	count = 0;
	while (1)
	{
		index = (index - 1 + philo->c_ph) % philo->c_ph;
		if (has_eaten_every(&philo->philo_ids[index]))
			count++;
		if (count == philo->c_ph)
			break ;
		else if (anyone_death(&philo->philo_ids[index]))
			break ;
		index++;
	}
	return (NULL);
}

static void	monitor(t_philo *ph)
{
	pthread_t	m;

	if (pthread_create(&m, NULL, &monitoring, (void *)ph) != 0)
		return ;
	if (pthread_join(m, NULL) != 0)
		return ;
	return ;
}

static void	try_sleep(t_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	if (ph->flag->died || has_eaten_every(ph))
	{
		pthread_mutex_unlock(ph->mutex);
		return ;
	}
	pthread_mutex_unlock(ph->mutex);
	printf("%ld Philo %ld is sleeping\n", new_time(ph) / 1000, ph->num);
	usleep(ph->t_sleep * 1000);
	if (has_eaten_every(ph))
		return ;
}

static void	*p(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (ph->flag->died || has_eaten_every(ph))
			break ;
		else
			try_fork_1(ph);
		if (ph->flag->died || has_eaten_every(ph))
			break ;
		else
			try_fork_2(ph);
		if (ph->flag->died || has_eaten_every(ph))
			break ;
		else
			try_sleep(ph);
	}
	return (NULL);
}

int	lets_go(t_philo *ph)
{
	int			i;
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
	monitor(ph);
	i = 0;
	while (i < ph->c_ph)
	{
		if (pthread_join(t[i], NULL) != 0)
			return (0);
		i++;
	}
	free(t);
	return (1);
}
