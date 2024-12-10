/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:14:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 21:14:48 by fruan-ba         ###   ########.fr       */
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
	else
	{
		write(1, "%", 1);
		return (-1);
	}
	return (printed);
}
