/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 15:59:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice(void *arg)
{
	int	value;
	int	*result;
	(void)arg;

	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	value = ((rand() % 6) + 1);
	*result = value;
	return ((void *)result);
}

int	main(void)
{
	int	*result;
	int	index;
	pthread_t	t1;

	index = 0;
	srand(time(NULL));
	if (pthread_create(&t1, NULL, &roll_dice, NULL) != 0)
		return (1);
	if (pthread_join(t1, (void **)&result) != 0)
		return (1);
	printf("Address result: %p\n", result);
	printf("Result: %d\n", *result);
	free(result);
	return (0);
}
