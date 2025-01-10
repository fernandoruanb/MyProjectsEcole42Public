/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:06:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 12:27:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int	target = 0;

void	*routine2(void *arg)
{
	(void)arg;
	target += 5;
	sleep(2);
	printf("Hello from thread: %d\n", target);
	printf("target incremented.\n");
	return (NULL);
}

void	*routine(void *arg)
{
	(void) arg;
	printf("What is my PID? %d\n", getpid());
	printf("Hello from threads.\n");
	sleep(2);
	printf("The target is: %d\n", target);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (2);
	if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	if (pthread_create(&t3, NULL, &routine2, NULL) != 0)
		return (5);
	if (pthread_join(t3, NULL) != 0)
		return (6);
	return (0);
}
