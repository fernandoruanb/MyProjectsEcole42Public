/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:28:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 16:41:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;

	index = *(int *)arg;
	printf("The primer selected is: %d\n", primes[index]);
	return (NULL);
}

int	main(void)
{
	int	index;
	pthread_t	ths[10];

	index = 0;
	while (index < 10)
	{
		if (pthread_create(&ths[index], NULL, &routine, &index) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < 10)
	{
		if (pthread_join(ths[index], NULL) != 0)
			return (1);
		index++;
	}
	return (0);
}
