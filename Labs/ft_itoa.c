/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:42:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 11:56:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

static int	calculate_how_many_numbers(int n);

char	*ft_itoa(int n);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 2)
		return (1);
	result = ft_itoa(ft_atoi(argv[1]));
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char	*buffer;
	int	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		num = -n;
	else
		num = n;
	length = calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		buffer[0] = '-';
	return (buffer);
}

static int	calculate_how_many_numbers(int n)
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
