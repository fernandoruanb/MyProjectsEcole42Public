/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:54:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 11:01:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;
	int		length;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	return (write(1, str, length));
}
