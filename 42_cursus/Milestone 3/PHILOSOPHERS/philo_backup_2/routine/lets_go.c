/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/14 09:04:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_died(t_philo *ph)
{
	static int	count = 0;
	static int	died = 0;

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
		died = 1;
		if (died == 1 && count == 0)
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

static long	get_time(t_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	gettimeofday(&ph->time, NULL);
	pthread_mutex_unlock(ph->mutex);
	return (ph->time.tv_sec * 1000000 + ph->time.tv_usec);
}

static void	try_catch_fork(t_philo *ph)
{
	printf("%ld Philo %ld is thinking\n", get_time(ph) / 1000, ph->num);
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	printf("%ld Philo %ld has taken a fork\n", get_time(ph) / 1000, ph->num);
	if (ph->id == ph->c_ph - 1)
		pthread_mutex_lock(&ph->forks[ph->id % ph->c_ph]);
	else
		pthread_mutex_lock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	printf("%ld Philo %ld has taken a fork\n", get_time(ph) / 1000, ph->num);
	if (check_died(ph))
		return ;
	ph->tl_meal = get_time(ph);
	ph->m_eaten++;
	printf("%ld Philo %ld is eating\n", get_time(ph) / 1000, ph->num);
	usleep(ph->t_eat * 1000);
	if (check_died(ph))
		return ;
	pthread_mutex_unlock(&ph->forks[ph->id % ph->c_ph]);
	pthread_mutex_unlock(&ph->forks[(ph->id + 1) % ph->c_ph]);
	printf("%ld Philo %ld is sleeping\n", get_time(ph) / 1000, ph->num);
	usleep(ph->t_sleep * 1000);
	if (check_died(ph))
		return ;
}

static void	*p(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (check_died(ph))
			break ;
		try_catch_fork(ph);
	}
	return ((void *)(long)1);
}

int	lets_go(t_philo *ph)
{
	int			i;
	void		*get;
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
		if (pthread_join(t[i], &get) != 0)
			return (0);
		if ((int)(long)get == 1)
			return (1);
		i++;
	}
	return (1);
}
