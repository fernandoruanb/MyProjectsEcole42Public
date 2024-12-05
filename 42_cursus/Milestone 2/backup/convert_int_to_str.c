/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:03:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 11:11:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calculate_how_many_numbers(int number)
{
	int	length;

	length = 0;
	if (number <= 0)
		length = 1;
	while (number)
	{
		length++;
		number /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int				length;
	char			*buffer;
	unsigned int	number;

	if (n < 0)
		number = -n;
	else
		number = n;
	length = calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0)
		buffer[0] = '-';
	return (buffer);
}

int	convert_int_to_str(va_list args)
{
	size_t	length;
	int		number;
	char	*buffer;
	int		result;

	number = va_arg(args, int);
	buffer = ft_itoa(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}
