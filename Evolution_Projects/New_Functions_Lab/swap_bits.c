/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:15:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/21 08:22:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet);

int	main(void)
{
	unsigned char	result;

	result = swap_bits(255);
	printf("%c\n", result);
	return (0);
}

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
