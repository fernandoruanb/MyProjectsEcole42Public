/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:11:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/29 11:18:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
 * Comparando expressões relacionais, lógicas e de
 * atribuição na linguagem C. Como podem perceber, o resultado
 * das expressões relacionais chegam primeiro para depois começar
 * o uso das expressões lógicas. Em seguida, finalizamos com a
 * expressão de atribuição. É válido citar que tanto as expressões relacionais
quanto as expressões lógicas retornam 0 ou 1, ou seja, booleanos.
É por meio desses booleanos que podemos realizar os nossos
testes.
 */
int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	c;
	int	result;

	if (argc < 3)
		return (1);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	result = a < b && b < c;
	printf("a < b && b < c: %i.\n", result);
	result = a < b || c < b;
	printf("a < b || c < b: %i.\n", result);
	return (0);
}
