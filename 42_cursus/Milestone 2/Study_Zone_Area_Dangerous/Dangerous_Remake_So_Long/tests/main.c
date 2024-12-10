/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 12:41:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	total;

	//ft_printf("%d\n", ft_printf("%c %c\n", 'a', 'b'));
	ft_printf("%c %c %s 100%%\n", 'a', 'b', "Fernando");
	ft_printf("%d %i %d\n", INT_MIN, INT_MAX, 0);
	ft_printf("%x %X %x %X\n", 255, 255, -255, -255);
	ft_printf("%u %u %u\n", UINT_MAX, 0, -255);
	ft_printf("%p %p\n", (void *)0, &total);
	return (0);
}
