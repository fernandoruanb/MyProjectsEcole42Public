/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:14:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 09:23:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	send_char(char c)
{
	int				index;
	unsigned char	character;

	character = (unsigned char)c;
	index = 7;
	while (index >= 0)
	{
		if (character >> index & 1)
			printf("1");
		else
			printf("0");
		index--;
	}
	printf("\n");
}

/*int	main(void)
{
	send_char('o');
	send_char('A');
	send_char('B');
	send_char('C');
	send_char('7');
	return (0);
}*/
