/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:33:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 14:38:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
		{
			write(1, "_", 1);
			argv[1][index] += 32;
			write(1, &argv[1][index], 1);
		}
		else
			write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
