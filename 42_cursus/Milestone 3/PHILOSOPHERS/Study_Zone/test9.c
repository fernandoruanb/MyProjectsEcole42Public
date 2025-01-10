/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:43:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/10 17:45:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	total = 0;

void	*routine(void *arg)
{
	int	number;

	number = *(int *)arg;
	total += number;
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	index;
	int	*number;
	pthread_t	t1[argc - 1];

	if (argc < 2)
		return (1);
	number = malloc((argc - 1) * sizeof(int));
	if (!number)
		return (1);
	index = 1;
	while (index < argc)
	{
		number[index - 1] = atoi(argv[index]);
		index++;
	}
	index = 0;
	while (index < argc - 1)
	{
		if (pthread_create(&t1[index], NULL, &routine, &number[index]) != 0)
			return (1);
		index++;
	}
	index = 0;
	while (index < argc - 1)
	{
		if (pthread_join(t1[index], NULL) != 0)
			return (1);
		index++;
	}
	printf("The result is: %d\n", total);
	return (0);
}
