/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:53:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 17:58:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet);

int	main(void)
{
	unsigned char	result;

	result = reverse_bits(2);
	printf("%d\n", result);
	return (0);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	index;
	unsigned char	result;

	index = 8;
	result = 0;
	while (index--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}
