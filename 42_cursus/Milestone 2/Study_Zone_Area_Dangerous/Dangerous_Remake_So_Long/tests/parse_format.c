/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:05:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 21:05:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *format, va_list args)
{
	int	temp;
	int	total;
	int	index;

	total = 0;
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index] != '\0')
		{
			index++;
			temp = handle_specifier(format[index], args);
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
