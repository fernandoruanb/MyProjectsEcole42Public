/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:28:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 13:15:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

int	mails = 0;

void	*routine(void *arg)
{
	int	index;

	index = 0;
	while (index < 1000000)
	{
		index++;
		mails++;
	}
	(void)arg;
	return (NULL);
}

int	main(void)
{
	int	threads;
	int	index;
	pthread_t	*m;

	threads = 5;
	m = malloc(threads * sizeof(pthread_t));
	if (!m)
		return (1);
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
	printf("You sent %d mails.\n", mails);
	return (0);
}
