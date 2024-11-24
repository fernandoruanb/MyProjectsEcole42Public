/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:24:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 08:28:59 by fruan-ba         ###   ########.fr       */
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
	while (argv[1][index] == ' ' || argv[1][index] == '\t')
		index++;
	while ((argv[1][index] != ' ' && argv[1][index] != '\t')
		&& (argv[1][index] != '\0'))
	{
		write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
