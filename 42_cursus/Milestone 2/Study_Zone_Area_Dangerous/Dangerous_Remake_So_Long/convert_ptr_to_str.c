/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:26:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 12:41:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	calculate_how_many_numbers(unsigned long n)
{
	unsigned long	length;

	length = 0;
	while (n)
	{
		length++;
		n /= 16;
	}
	return (length);
}

static char	*ft_itoa_ptr(unsigned long n)
{
	char	*hex_digits;
	unsigned long	length;
	char	*buffer;

	length = calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	hex_digits = "0123456789abcdef";
	while (length--)
	{
		buffer[length] = hex_digits[n % 16];
		n /= 16;
	}
	return (buffer);
}

int	convert_ptr_to_str(va_list args)
{
	int	length;
	int	result;
	char	*buffer;
	unsigned long	number;

	number = (unsigned long)va_arg(args, void *);
	if (number == 0)
		return (write(1, "(nil)", 5));
	buffer = ft_itoa_ptr(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, "0x", 2);
	result += write(1, buffer, length);
	free(buffer);
	return (result);
}
