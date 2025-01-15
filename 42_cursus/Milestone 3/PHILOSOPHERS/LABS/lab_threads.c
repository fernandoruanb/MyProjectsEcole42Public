/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:37:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/15 10:31:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t	mutex;
int	stop_execution = 0;
int	global_count = 0;

void	*monitor(void *arg)
{
	(void)arg;
	while (!stop_execution)
	{
		if (global_count >= 10)
			stop_execution = 1;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&mutex);
	if (!stop_execution && (global_count + 2) <= 10)
	{
		global_count += 2;
		printf("Count: %d\n", global_count);
		if (global_count != 10)
			printf("Anything that I don't need to know\n");
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		pthread_mutex_unlock(&mutex);
		return (NULL);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	*t;
	pthread_t	m;
	int	index;

	index = 0;
	t = malloc(100 * sizeof(pthread_t));
	if (!t)
		return (1);
	if (pthread_create(&m, NULL, &monitor, NULL) != 0)
		return (1);
	pthread_mutex_init(&mutex, NULL);
	while (index < 100)
	{
		if (pthread_create(&t[index], NULL, &routine, NULL) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < 100)
	{
		if (pthread_join(t[index], NULL) != 0)
			return (1);
		index++;
	}
	if (pthread_join(m, NULL) != 0)
		return (1);
	pthread_mutex_destroy(&mutex);
	free(t);
	return (0);
}
