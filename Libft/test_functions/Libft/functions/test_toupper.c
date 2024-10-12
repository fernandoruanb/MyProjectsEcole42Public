/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:01:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/12 12:34:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft.h"

int	main(void)
{
	printf("_______2048 -> True | 0 -> False______\n");
	printf("Teste 1: Caracter -> %c | Result -> %i\n", 'a', ft_toupper('a'));
	printf("Teste 2: Caracter -> %c | Result -> %i\n", 'z', ft_toupper('Z'));
	printf("Teste 3: Caracter -> %c | Result -> %i\n", 'm', ft_toupper('m'));
	printf("Teste 4: Caracter -> %c | Result -> %i\n", 'G', ft_toupper('G'));
	printf("Teste 5: Caracter -> %c | Result: %i\n", '1', ft_toupper('1'));
	printf("Teste 6: Caracter -> %c | Result: %i\n", '9', ft_toupper('9'));
	printf("Teste 7: Caracter -> %c | Result: %i\n", '!', ft_toupper('!'));
	printf("Teste 8: Caracter -> %c | Result: %i\n", '@', ft_toupper('@'));
	printf("Teste 9: Caracter -> %c' ' |Result: %i\n", ' ', ft_toupper(' '));
	printf("Teste 10: Caracter -> %c | Result: %i\n", '&', ft_toupper('&'));
	printf("Teste 11: Caracter > %c'\\n' | Result: %i\n", '\n', ft_toupper('\n'));
	printf("Teste 12: Caracter -> %c | Result: %i\n", '0', ft_toupper('0'));
	printf("Teste 13: Caracter -> %c | Result: %i\n", '#', ft_toupper('#'));
	printf("Teste 14: Caracter -> %c | Result: %i\n", ']', ft_toupper(']'));
	printf("Teste 15: Caracter -> %c | Result: %i\n", '+', ft_toupper('+'));
	printf("Teste 16: Caracter -> %c | Result: %i\n", '_', ft_toupper('_'));
	printf("Teste 17: Caracter -> %c | Result: %i\n", '~', ft_toupper('~'));
	printf("Teste 18: Caracter -> %c | Result: %i\n", '?', ft_toupper('?'));
	printf("Teste 19: Caracter -> %c | Result: %i\n", ':', ft_toupper(':'));
	printf("Teste 20: Caracter -> %c | Result: %i\n", '%', ft_toupper('%'));
	printf("____________FINISHED :D_______________\n");
	return (0);
}
