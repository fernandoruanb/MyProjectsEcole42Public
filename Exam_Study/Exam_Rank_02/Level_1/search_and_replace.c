/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:46:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 13:59:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;

	if (argc < 4 || argc > 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		if (argv[1][index] == argv[2][0])
			write(1, &argv[3][0], 1);
		else
			write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
