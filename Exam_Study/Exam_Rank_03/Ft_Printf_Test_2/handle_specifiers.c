/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:34:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 11:51:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifiers(const char *format, int index, va_list args)
{
	int	printed;

	printed = 0;
	if (format[index] == 'c')
		printed = print_char(args);
	else if (format[index] == 's')
		printed = print_str(args);
	else if (format[index] == 'd' || format[index] == 'i')
		printed = convert_int_to_str(args);
	else if (format[index] == 'x' || format[index] == 'X')
		printed = convert_hex_to_str(args, format[index]);
	else if (format[index] == '%' && format[index + 1] != '\0')
		printed = print_percentage();
	else
	{
		if (format[index + 1] == '\n') 
			write(1, "%\n", 2);
		return (-1);
	}
	return (printed);
}
