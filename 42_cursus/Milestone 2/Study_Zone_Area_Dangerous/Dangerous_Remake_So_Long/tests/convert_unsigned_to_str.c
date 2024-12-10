/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:18:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 12:19:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	calculate_how_many_numbers(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_itoa_uns(unsigned int n)
{
	char	*buffer;
	unsigned int	length;

	length = calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (n % 10) + '0';
		n /= 10;
	}
	return (buffer);
}

int	convert_unsigned_to_str(va_list args)
{
	int	length;
	int	result;
	char	*buffer;
	unsigned int number;

	number = va_arg(args, unsigned int);
	buffer = ft_itoa_uns(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}
