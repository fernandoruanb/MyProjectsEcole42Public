/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:53:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/20 16:02:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	a;
	unsigned int	b;
	
	a = -4294967295;
	printf("%u\n", UINT_MAX - UINT_MAX);
	ft_printf("%u\n", UINT_MAX - UINT_MAX);
	printf("%u\n", 4294967295 - 4294967295);
	ft_printf("%u\n", 4294967295 - 4294967295);
	printf("%u\n", a);
	ft_printf("%u\n", a);
	return (0);
}
