/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:29:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 17:33:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet);

int	main(void)
{
	print_bits(2);
	write(1, "\n", 1);
	return (0);
}

void	print_bits(unsigned char octet)
{
	int	index;
	unsigned char	digit;
	
	index = 8;
	while (index--)
	{
		digit = ((octet >> index) & 1) + '0';
		write(1, &digit, 1);
	}
}
