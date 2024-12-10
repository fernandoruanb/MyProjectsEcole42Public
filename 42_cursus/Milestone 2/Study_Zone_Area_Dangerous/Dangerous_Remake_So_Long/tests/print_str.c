/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:06:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 22:06:53 by fruan-ba         ###   ########.fr       */
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
