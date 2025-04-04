/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:54:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 09:55:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h>  

void	*routine(void *arg)
{
	(void)arg;
	printf("Test from threads.\n");
	sleep(3);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	printf("Executando a primeira thread.\n");
	pthread_join(t1, NULL);
	printf("Terminou a primeira thread.\n");
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);
	printf("Executando a segunda thread\n");
	pthread_join(t2, NULL);
	printf("Terminou a segunda thread.\n");
	return (0);
}
