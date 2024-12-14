/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:28:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 15:06:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, unsigned char *message)
{
	int	index;
	int	s_index;
	int	bit;

	index = 0;
	while (message[index] != '\0')
	{
		s_index = 0;
		while (s_index < 8)
		{
			message[index] & 1
			message[index] << 1
			s_index++;
		}
		index++;
	}
}
