/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:04:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/13 10:46:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *format, va_list args)
{
	int	total;
	int	index;

	total = 0;
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
		{
			index++;
			if (handle_specifier(format[index], args) == -1)
				return (-1);
			total += handle_specifier(format[index], args);
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
