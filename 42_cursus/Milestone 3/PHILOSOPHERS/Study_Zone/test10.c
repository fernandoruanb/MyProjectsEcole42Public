/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:24:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 18:45:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t	mutex;

/*void	*routine(void *arg)
{
	(void)arg;
	if (pthread_mutex_trylock(&mutex) == 0)
	{
		printf("Got lock!\n");
		sleep(1); //Loading...
		pthread_mutex_unlock(&mutex);
	}
	else
		printf("Unfortunately, failed getting lock.\n");
	return (NULL);
}*/

void	*routine(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&mutex);
	printf("Got lock!\n");
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(void)
{
	int	index;
	pthread_t	th[4];

	index = 0;
	pthread_mutex_init(&mutex, NULL);
	while (index < 4)
	{
		if (pthread_create(&th[index], NULL, &routine, NULL) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < 4)
	{
		if (pthread_join(th[index], NULL) != 0)
			return (1);
		index++;
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}
