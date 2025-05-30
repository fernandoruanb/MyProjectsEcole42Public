/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:33:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 11:45:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list args)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(args);
	else if (specifier == 's')
		printed = print_str(args);
	else if (specifier == '%')
		printed = print_percentage();
	else if (specifier == 'i' || specifier == 'd')
		printed = convert_int_to_str(args);
	else if (specifier == 'u')
		printed = convert_unsigned_to_str(args);
	else if (specifier == 'x' || specifier == 'X')
		printed = convert_hex_to_str(args, specifier);
	else if (specifier == 'p')
		printed = convert_ptr_to_str(args);
	else
	{
		write(1, "%", 1);
		return (-1);
	}
	return (printed);
}
