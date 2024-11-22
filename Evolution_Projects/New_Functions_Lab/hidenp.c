/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:45:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/22 18:51:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;
	int	s_index;

	if (argc == 3)
	{
		index = 0;
		s_index = 0;
		while (argv[1][index] && argv[2][s_index])
		{
			if (argv[1][index] == argv[2][s_index])
				index++;
			s_index++;
		}
		if (argv[1][index] == '\0')
			write(1, "1", 1);
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return (0);
}
