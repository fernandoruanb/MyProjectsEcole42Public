/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:12:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 16:38:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	int	result;

	result = ft_printf("%c %s 100%% %d %i %x %X\n", 'a',
		"Fernando", INT_MAX, INT_MIN, 255, -255);
	ft_printf("Quantidade de caracteres: %d\n", result);
	return (0);
}
