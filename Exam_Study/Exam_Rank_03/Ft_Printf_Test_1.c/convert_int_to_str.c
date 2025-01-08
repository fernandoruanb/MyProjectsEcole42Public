/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:31:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 16:33:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_how_many_numbers(int num)
{
	int	length;

	length = 0;
	if (num <= 0)
		length = 1;
	while (num)
	{
		num /= 10;
		length++;
	}
	return (length);
}

static char	*ft_itoa(int num)
{
	char			*buffer;
	int				length;
	unsigned int	number;

	if (num < 0)
		number = -num;
	else
		number = num;
	length = calculate_how_many_numbers(num);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = (number % 10) + '0';
		number /= 10;
	}
	if (num < 0)
		buffer[0] = '-';
	return (buffer);
}

int	convert_int_to_str(va_list args)
{
	char	*buffer;
	int		length;
	int		number;
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
