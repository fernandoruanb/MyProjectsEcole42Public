/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:39:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 18:05:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		calculate_how_many_numbers(int n);

char	*ft_itoa(int nbr);

int	main(int argc, char **argv)
{
	char	*result;

	result = ft_itoa(atoi(argv[1]));
	printf("O resultado ficou: %s\n", result);
	return (0);
}

char	*ft_itoa(int nbr)
{
	int				index;
	char			*buffer;
	int				length;
	unsigned int	number;

	if (nbr < 0)
		number = -nbr;
	else
		number = nbr;
	length = calculate_how_many_numbers(nbr);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	while (length--)
	{
		buffer[length] = (number % 10) + '0';
		number /= 10;
	}
	if (nbr < 0)
		buffer[0] = '-';
	return (buffer);
}

int	calculate_how_many_numbers(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}
