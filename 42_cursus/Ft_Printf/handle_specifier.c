/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:12:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/11 14:33:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	handle_specifier(char specifier, va_list args)
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
	else if (specifier == 'u')
		printed = convert_unsigned_to_str(args);
	else if (specifier == '%')
		printed = print_percentage();
	else if (specifier == 'p')
		printed = print_pointer(args);
	else
		printed = write_to_output('%');
	return (printed);
}
