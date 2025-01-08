/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:09:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 16:31:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifiers(char specifier, va_list args)
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
