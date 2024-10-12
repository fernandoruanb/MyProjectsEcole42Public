/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:23:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/12 12:26:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft.h"

int	main(void)
{
	printf("_______16384 -> True | 0 -> False______\n");
	printf("Teste 1: Caracter -> %c | Result -> %i\n", 'a', ft_isprint('a'));
	printf("Teste 2: Caracter -> %c | Result -> %i\n", 'z', ft_isprint('Z'));
	printf("Teste 3: Caracter -> %c | Result -> %i\n", 'm', ft_isprint('m'));
	printf("Teste 4: Caracter -> %c | Result -> %i\n", 'G', ft_isprint('G'));
	printf("Teste 5: Caracter -> %c | Result: %i\n", '1', ft_isprint('1'));
	printf("Teste 6: Caracter -> %c | Result: %i\n", '9', ft_isprint('9'));
	printf("Teste 7: Caracter -> %c | Result: %i\n", '!', ft_isprint('!'));
	printf("Teste 8: Caracter -> %c | Result: %i\n", '@', ft_isprint('@'));
	printf("Teste 9: Caracter -> %c' ' | Result: %i\n", ' ', ft_isprint(' '));
	printf("Teste 10: Caracter -> %c | Result: %i\n", '&', ft_isprint('&'));
	printf("Teste 11: Caracter > %c'\\n' | Result: %i\n", '\n', ft_isprint('\n'));
	printf("Teste 12: Caracter -> %c | Result: %i\n", '0', ft_isprint('0'));
	printf("Teste 13: Caracter -> %c | Result: %i\n", '#', ft_isprint('#'));
	printf("Teste 14: Caracter -> %c | Result: %i\n", ']', ft_isprint(']'));
	printf("Teste 15: Caracter -> %c | Result: %i\n", '+', ft_isprint('+'));
	printf("Teste 16: Caracter -> %c | Result: %i\n", '_', ft_isprint('_'));
	printf("Teste 17: Caracter -> %c | Result: %i\n", '~', ft_isprint('~'));
	printf("Teste 18: Caracter -> %c | Result: %i\n", '?', ft_isprint('?'));
	printf("Teste 19: Caracter -> %c | Result: %i\n", ':', ft_isprint(':'));
	printf("Teste 20: Caracter -> %c | Result: %i\n", '%', ft_isprint('%'));
	printf("____________FINISHED :D_______________\n");
	return (0);
}
