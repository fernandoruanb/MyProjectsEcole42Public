/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/29 11:29:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
 * Os incrementadores e decrementadores funcionam em C em pré ou
 * pós incrementação e decrementação como podemos ver logo abaixo.
 */
int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	result;

	if (argc < 3)
		return (1);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	result = a;
	printf("O valor inicial de a é: %i.\n", a);
	printf("O valor de a adicionado antes: %i.\n", ++a);
	printf("O valor de a adicionado depois: %i.\n", a++);
	printf("Valor de a atual: %i.\n", a);
	printf("Valor de b atual decrementado após: %i.\n", b--);
	printf("Valor de b após b-- : %i.\n", b);
	return (0);
}
