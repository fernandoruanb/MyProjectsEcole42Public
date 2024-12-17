/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:20:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 09:43:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	send_char(char c);

int	main(int argc, char **argv)
{
	int	index;

	if (argc != 2)
	{
		printf("How to use: type a message to see each char bit.\n");
		return (1);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		send_char(argv[1][index]);
		index++;
	}
	send_char('\0');
	return (0);
}
