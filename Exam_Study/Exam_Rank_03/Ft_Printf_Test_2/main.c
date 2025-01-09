/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:01:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 11:50:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	total;

	total = ft_printf("%c %s %d %i %x %X 100%%\n",
		'c', "Fernando", INT_MAX, INT_MIN, 255, -255);
	ft_printf("Total: %d\n", total);
	printf("%d\n", printf("ORIGINAL_1 100 %z\n %"));
	ft_printf("%d\n", ft_printf("ORIGINAL_2 100 %z\n %"));
	return (0);
}
