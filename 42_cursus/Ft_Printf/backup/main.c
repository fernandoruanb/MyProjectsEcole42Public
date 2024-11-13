/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:21:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/13 11:23:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	x;

	x = 42;
	printf("Meu nome é: %s\n", "Fernando");
	ft_printf("Meu nome é: %s\n", "Fernando");
	printf("O número é: %d e também %i %d %d %i\n", 42, 21, -12, -2147483648, -2147483648);
	ft_printf("O número é: %d e também %i %d %d %i\n", 42, 21, -12, -2147483648, -2147483648);
	printf("O caracter é: %c\n", 'a');
	ft_printf("O caracter é: %c\n", 'a');
	printf("5%%\n");
	ft_printf("5%%\n");
	printf("%u, %x, %X, %x\n", 2147483647, 255, 255, -255);
	ft_printf("%u, %x, %X, %x\n", 2147483647, 255, 255, -255);
	printf("%p\n", &x);
	ft_printf("%p\n", &x);
	printf("%d %i\n", 2147483647, 2147483647);
	ft_printf("%d %i\n", 2147483647, 2147483647);
	printf("%p\n", (void *)0);
	ft_printf("%p\n", (void *)0);
	x = printf("Meu nome é %s e tenho %d anos\n", "Fernando", 23);
	printf("%d\n", x);
	x = ft_printf("Meu nome é %s e tenho %d anos\n", "Fernando", 23);
	printf("%d\n", x);
	x = printf("%c %s %d %i %u %p %p %x %X %x %X 100%% %z", 'a', "Fernando", 22, 42, 294967295, &x, (void *)0, 255, 255, -255, -255);
	printf("%d\n", x);
	x = ft_printf("%c %s %d %i %u %p %p %x %X %x %X 100%% %z", 'a', "Fernando", 22, 42, 294967295, &x, (void *)0, 255, 255, -255, -255);
	printf("%d\n", x);
	printf("%z\n");
	ft_printf("%z");
	return (0);
}
