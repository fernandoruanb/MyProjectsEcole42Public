/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:42:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 13:37:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	static unsigned char	buffer;
	static int				index;

	buffer = 0;
	index = 0;
	if (SIGUSR1 == signum)
	{
		buffer = buffer << 1 | 0;
		index++;
	}
	else if (SIGUSR2 == signum)
	{
		buffer = buffer << 1 | 1;
		index++;
	}
	if (index == 8)
	{
		print_char(buffer);
		buffer = 0;
		index = 0;
	}
}
