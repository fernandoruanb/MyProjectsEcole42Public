/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:03:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 11:56:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ul_calculate_how_many_numbers(unsigned long number)
{
	unsigned long	length;

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

char	*ft_itoa_un_long(unsigned long n)
{
	int		length;
	char	*buffer;
	char	*hex_digit;

	length = ul_calculate_how_many_numbers(n);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	hex_digit = "0123456789abcdef";
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = hex_digit[n % 16];
		n /= 16;
	}
	return (buffer);
}

int	convert_ptr_to_str(va_list args)
{
	size_t			length;
	unsigned long	number;
	char			*buffer;
	int				result;

	number = (unsigned long)va_arg(args, void *);
	if (number == 0)
		return (write(1, "(nil)", 5));
	buffer = ft_itoa_un_long(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, "0x", 2);
	result += write(1, buffer, length);
	free(buffer);
	return (result);
}
