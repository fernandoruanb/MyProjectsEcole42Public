/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:58:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 11:03:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	*routine(void *arg)
{
	(void)arg;
	printf("Executando a routina.\n");
	sleep(3);
	printf("Terminando a routina.\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	printf("Criando thread t1.\n");
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	printf("Execução da t1.\n");
	if (pthread_join(t1, NULL) != 0)
		return (1);
	printf("Término da t1.\n");
	printf("Criando thread t2.\n");
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);
	printf("Execução da t2.\n");
	if (pthread_join(t2, NULL) != 0)
		return (1);
	printf("Término da t2.\n");
	return (0);
}
