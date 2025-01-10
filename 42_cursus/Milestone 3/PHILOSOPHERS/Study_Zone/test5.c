/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:10:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 14:29:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

unsigned long long	mails = 0;
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	unsigned long long	index;
	(void)arg;

	index = 0;
	pthread_mutex_lock(&mutex);
	while (index < 1000000)
	{
		index++;
		mails++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	unsigned long long	index;
	unsigned long long	threads;
	pthread_t	*ths;

	if (argc != 2)
		return (1);
	threads = atol(argv[1]);
	ths = malloc(threads * sizeof(pthread_t));
	if (!ths)
		return (1);
	index = 0;
	pthread_mutex_init(&mutex, NULL);
	while (index < threads)
	{
		if (pthread_create(&ths[index], NULL, &routine, NULL) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < threads)
	{
		if (pthread_join(ths[index], NULL) != 0)
			return (1);
		index++;
	}
	pthread_mutex_destroy(&mutex);
	printf("You sent %lld mails.\n", mails);
	return (0);
}
