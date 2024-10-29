/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:43:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/29 10:43:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	result;

	if (argc < 3)
		return (1);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	result = a + b * 2;
	printf("Resultado de a + b * 2: %i.\n", result);
	result = (a + b) * 2;
	printf("Resultado de (a + b) * 2: %i.\n", result);
	result = a / b - 2;
	printf("Resultado de a / b - 2 : %i.\n", result);
	result = a / (b - 2);
	printf("Resultado de a / (b - 2): %i.\n", result);
	return (0);
}
