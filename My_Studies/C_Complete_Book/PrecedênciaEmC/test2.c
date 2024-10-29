/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:57:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/29 10:57:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
Expressões Aritméticas e Expressões Relacionais em C.

Expressões Aritméticas usam o PENDAS
P -> Potenciação
E -> Exponenciação
N -> Multiplicação
D -> Divisão
A -> Adição
S -> Subtração

a + b * c
A prioridade será o b * c primeiro pelo PENDAS
(a + b) * c
Como estudamos as demais precedências, os () possuem a maior
precedência. Portanto, a operação aritmética da adição
prevalece nesse caso.
*/
int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	c;
	int	result;

	if (argc < 4)
		return (1);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	result = a + b * c;
	printf("a + b * c = %i.\n", result);
	result = (a + b) * c;
	printf("(a + b) * c = %i.\n", result);
	return (0);
}
