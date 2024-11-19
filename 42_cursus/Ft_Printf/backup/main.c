/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:21:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/14 17:25:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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
	x = printf("%c %s %d %i %u %p %p %x %X %x %X 100%%", 'a', "Fernando", 22, 42, 294967295, &x, (void *)0, 255, 255, -255, -255);
	printf("%d\n", x);
	x = ft_printf("%c %s %d %i %u %p %p %x %X %x %X 100%%", 'a', "Fernando", 22, 42, 294967295, &x, (void *)0, 255, 255, -255, -255);
	ft_printf("%d\n", x);
	printf("%z\n");
	ft_printf("%z\n");
	printf(NULL);
	ft_printf(NULL);
	x = printf(NULL);
	printf("%d\n", x);
	x = ft_printf(NULL);
	printf("%d\n\n", x);
	/* ************************************************************ */
	/* 			MAIS TESTES :D                          */
	/* **************************************************************/

	ft_printf("0 - %s\n", "Olá, Mundo!");
	ft_printf("1 - Número inteiro: %d\n", 42);
	ft_printf("2 - Caractere: %c\n", 'A');
	ft_printf("3 - String: %s\n", "Teste");
	ft_printf("4 - Unsigned int: %u\n", 3000000000);
	ft_printf("5 - Hexadecimal minúsculo: %x\n", 255);
	ft_printf("6 - Hexadecimal maiúsculo: %X\n", 255);
	ft_printf("7 - Endereço de Memória %p\n", &x);
	ft_printf("8 - Porcentagem: 100%%\n");
	ft_printf("Vários argumentos %d, %s, %c\n", 10, "texto", 'Z');
	ft_printf("Número negativo: %d\n", -123);
	ft_printf("Unsigned com número negativo: %u\n", -1);
	ft_printf("String Nula: %s\n", NULL);
	ft_printf("Ponteiro nulo: %p\n", (void *)0);
	ft_printf("Número máximo int: %d\n", INT_MAX);
	ft_printf("Número mínimo int %d\n", INT_MIN);
	ft_printf("Unsigned máximo: %u\n", UINT_MAX);
	ft_printf("Hexadecimal de 0: %x\n", 0);
	ft_printf("Caractere não imprimível: %c (enter)", '\n');
	ft_printf("Sem especificador: %\n");
	ft_printf("Porcentagem dupla %%\n");
	ft_printf("Número grande: %d\n", 2147483647);
	ft_printf("Número negativo grande: %d\n", -2147483648);
	ft_printf("Mix: %s %d %x\n", "Valor", 255, 255);
	ft_printf("Caractere negativo: %c\n", -100);
	ft_printf("Limite unsigned: %u\n", 4294967295);
	ft_printf("Hexadecimal com prefixo: 0x%x\n", 48879);
	return (0);
}
