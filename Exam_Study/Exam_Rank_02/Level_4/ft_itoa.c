/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:11:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/29 13:20:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	calculate_how_many_numbers(int nbr);

char	*ft_itoa(int nbr);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = ft_itoa(atoi(argv[1]));
	printf("%s\n", result);
	free(result);
	return (0);
}

char	*ft_itoa(int nbr)
{
	int	length;
	char	*buffer;
	unsigned int	number;

	if (nbr < 0)
		number = -nbr;
	else
		number = nbr;
	length = calculate_how_many_numbers(nbr);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (number % 10) + '0';
		number /= 10;
	}
	if (nbr < 0)
		buffer[0] = '-';
	return (buffer);
}

int	calculate_how_many_numbers(int nbr)
{
	int	length;

	length = 0;
	if (nbr <= 0)
		length = 1;
	while (nbr)
	{
		nbr /= 10;
		length++;
	}
	return (length);
}
