/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:01:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 16:14:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice(void *arg)
{
	int	value;
	int	*result;

	(void)arg;
	value = (rand() % 6) + 1;
	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	*result = value;
	return ((void *)result);
}

int	main(int argc, char **argv)
{
	int	index;
	int	threads;
	int	*result;
	pthread_t	*ths;

	if (argc != 2)
		return (1);
	threads = atoi(argv[1]);
	ths = malloc(threads * sizeof(pthread_t));
	if (!ths)
		return (1);
	index = 0;
	while (index < threads)
	{
		if (pthread_create(&ths[index], NULL, &roll_dice, NULL) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < threads)
	{
		if (pthread_join(ths[index], (void **)&result) != 0)
			return (1);
		printf("Address %p\n", result);
		printf("Result: %d\n", *result);
		index++;
	}
	return (0);
}
