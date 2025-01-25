/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_5_Multiple_Pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:01:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 15:55:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	index;
	int	pipefd[1024][2];

	index = 0;
	while (index < argc - 1)
	{
		if (pipe(pipefd[index]) == -1)
		{
			while (index > 0)
			{
				index--;
				close_descriptors(pipefd[index], NULL);
			}
		}
			return (ft_putendl_1("Error creating pipe.\n"));
		index++;
	}
	return (0);
}
