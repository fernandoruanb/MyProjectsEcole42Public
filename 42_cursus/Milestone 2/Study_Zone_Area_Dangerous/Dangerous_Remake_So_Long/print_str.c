/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:41:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 16:51:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	int		length;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	length = ft_strlen(str);
	return (write(1, str, length));
}
