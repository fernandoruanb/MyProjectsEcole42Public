/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:13:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 16:39:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

static unsigned int	calculate_how_many_numbers_2(unsigned int n)
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
	char	*buffer;
	char	*hex_digits;
	unsigned int	length;

	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	length = calculate_how_many_numbers_2(num);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = hex_digits[num % 16];
		num /= 16;
	}
	return (buffer);
}

static int	convert_hex_to_str(va_list args, char specifier)
{
	int	result;
	char	*buffer;
	int	length;
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
	int	length;
	char	*buffer;
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

static int	convert_int_to_str(va_list args)
{
	char	*buffer;
	int	length;
	int	result;
	int	number;

	number = va_arg(args, int);
	buffer = ft_itoa(number);
	if (!buffer)
		return (0);
	length = ft_strlen(buffer);
	result = write(1, buffer, length);
	free(buffer);
	return (result);
}

static int	print_percentage(void)
{
	return (write(1, "%", 1));
}

static int	print_str(va_list args)
{
	int	length;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	return (write(1, str, length));
}

static int	print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

static int	handle_specifiers(char specifier, va_list args)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(args);
	else if (specifier == 's')
		printed = print_str(args);
	else if (specifier == 'd' || specifier == 'i')
		printed = convert_int_to_str(args);
	else if (specifier == 'x' || specifier == 'X')
		printed = convert_hex_to_str(args, specifier);
	else if (specifier == '%')
		printed = print_percentage();
	else
	{
		write(1, "%", 1);
		return (-1);
	}
	return (printed);
}

static int	parse_args(const char *format, va_list args)
{
	int	temp;
	int	total;
	int	index;

	total = 0;
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
		{
			index++;
			temp = handle_specifiers(format[index], args);
			if (temp == -1)
				return (-1);
			total += temp;
		}
		else
		{
			write(1, &format[index], 1);
			total++;
		}
		index++;
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	total;

	if (!format)
		return (-1);
	total = 0;
	va_start(args, format);
	total += parse_args(format, args);
	va_end(args);
	return (total);
}

int	main(void)
{
	int	total;

	total = ft_printf("%c %s %d %i %x %X 100%%\n", 'a', "Fernando", INT_MAX, INT_MIN, 255, -255);
	ft_printf("%d\n", total);
	return (0);
}
