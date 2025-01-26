/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:03:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 11:33:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	hex_calculate_how_many_numbers(unsigned int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number)
	{
		length++;
		number /= 16;
	}
	return (length);
}

char	*ft_itoa_hex(unsigned int n, char specifier)
{
	int		length;
	char	*buffer;
	char	*hex_digit;

	length = hex_calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	if (specifier == 'x')
		hex_digit = "0123456789abcdef";
	else
		hex_digit = "0123456789ABCDEF";
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = hex_digit[n % 16];
		n /= 16;
	}
	return (buffer);
}

int	convert_hex_to_str(va_list args, char specifier)
{
	size_t			length;
	unsigned int	number;
	char			*buffer;
	int				result;

	number = va_arg(args, unsigned int);
	buffer = ft_itoa_hex(number, specifier);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}
