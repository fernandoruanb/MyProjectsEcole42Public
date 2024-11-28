/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:18:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/28 12:24:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;

	index = 0;
	while (argv[1][index] != '\0')
	{
		while ((argv[1][index]) && (argv[1][index]))
		while ((argv[1][index] < 'a' || argv[1][index] > 'z')
			&& (argv[1][index] < 'A' && argv[1][index] > 'Z'))
		{
			write(1, &argv[1][index], 1);
			index++;
		}
		if ((argv[1][index] >= 'a' && argv[1][index] <= 'z') &&
			(argv[1][index - 1] == ' ' || argv[1][index - 1] == '\t'))
		{
			argv[1][index] -= 32;
			write(1, &argv[1][index], 1);
			index++;
		}
		while ((argv[1][index] >= 'a' && argv[1][index] <= 'z')
			|| (argv[1][index] >= 'A' && argv[1][index] <= 'Z'))
		{
			write(1, &argv[1][index], 1);
			index++;
		}
	}
}
