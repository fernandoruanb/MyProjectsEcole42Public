/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:23:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 16:32:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	int		length;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	return (write(1, str, length));
}
