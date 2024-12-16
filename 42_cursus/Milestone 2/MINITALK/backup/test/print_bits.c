/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:31:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/15 15:47:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_bits(char character)
{
	int	index;
	int	bit;

	index = 7;
	while (index >= 0)
	{
		bit = (character >> index) & 1;
		printf("%d", bit);
		index--;
	}
	printf("\n");
	return (0);
}
