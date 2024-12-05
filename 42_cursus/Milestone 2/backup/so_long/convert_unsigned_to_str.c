/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:03:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 11:29:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	un_calculate_how_many_numbers(unsigned int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number)
	{
		length++;
		number /= 10;
	}
	return (length);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		length;
	char	*buffer;

	length = un_calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (n % 10) + '0';
		n /= 10;
	}
	if (n < 0)
		buffer[0] = '-';
	return (buffer);
}

int	convert_unsigned_to_str(va_list args)
{
	size_t			length;
	unsigned int	number;
	char			*buffer;
	int				result;

	number = va_arg(args, unsigned int);
	buffer = ft_itoa_unsigned(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}
