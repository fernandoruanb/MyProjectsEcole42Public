/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 09:46:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	//ft_printf("%d\n", ft_printf("%c %c\n", 'a', 'b'));
	ft_printf("%c %c %s 100%%\n", 'a', 'b', "Fernando");
	ft_printf("%d %i\n", INT_MIN, INT_MAX);
	ft_printf("%x %X %x %X\n", 255, 255, -255, -255);
	return (0);
}
