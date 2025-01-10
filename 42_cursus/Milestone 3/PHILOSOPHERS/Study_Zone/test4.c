/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:28:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 13:34:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

unsigned long long	mails = 0;
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	unsigned long long	index;

	index = 0;
	pthread_mutex_lock(&mutex);
	while (index < 1000000)
	{
		//pthread_mutex_lock(&mutex);
		index++;
		mails++;
		//pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&mutex);
	(void)arg;
	return (NULL);
}

int	main(int argc, char **argv)
{
	unsigned long long	threads;
	unsigned long long	index;
	pthread_t	*m;

	if (argc != 2)
		return (1);
	threads = atoi(argv[1]);
	m = malloc(threads * sizeof(pthread_t));
	if (!m)
		return (1);
	pthread_mutex_init(&mutex, NULL);
	index = 0;
	while (index < threads)
	{
		if (pthread_create(&m[index], NULL, &routine, NULL) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < threads)
	{
		if (pthread_join(m[index], NULL) != 0)
			return (1);
		index++;
	}
	pthread_mutex_destroy(&mutex);
	printf("You sent %llu mails.\n", mails);
	return (0);
}
