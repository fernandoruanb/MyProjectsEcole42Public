/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:13:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 11:37:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_args(const char *format, va_list args)
{
	int	temp;
	int	total;
	int	index;

	index = 0;
	total = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			temp = handle_specifiers(format, index, args);
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