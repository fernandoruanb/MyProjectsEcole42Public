/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:40:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 15:54:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	calculate_how_many_numbers(unsigned int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n)
	{
		n /= 16;
		length++;
	}
	return (length);
}

static char	*ft_itoa_hex(unsigned int num, char specifier)
{
	char			*buffer;
	unsigned int	length;
	char			*hex_digits;

	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	length = calculate_how_many_numbers(num);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (hex_digits[num % 16]);
		num /= 16;
	}
	return (buffer);
}

int	convert_hex_to_str(va_list args, char specifier)
{
	int				length;
	int				result;
	char			*buffer;
	unsigned int	number;

	number = va_arg(args, unsigned int);
	buffer = ft_itoa_hex(number, specifier);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}
