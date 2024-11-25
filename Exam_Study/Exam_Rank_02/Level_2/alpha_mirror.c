/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:07:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 14:30:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(char c);

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
		if ((argv[1][index] < 'a' || argv[1][index] > 'z')
			&& (argv[1][index] < 'A' || argv[1][index] > 'Z'))
			write(1, &argv[1][index], 1);
		alpha_mirror(argv[1][index]);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}

void	alpha_mirror(char c)
{
	int		index;
	char	*alphabet_l;
	char	*alphabet_u;

	index = 0;
	alphabet_l = "abcdefghijklmnopqrstuvwxyz";
	alphabet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (alphabet_l[index] != '\0')
	{
		if (alphabet_l[index] == c)
			write(1, &alphabet_l[25 - index], 1);
		index++;
	}
	index = 0;
	while (alphabet_u[index] != '\0')
	{
		if (alphabet_u[index] == c)
			write(1, &alphabet_u[25 - index], 1);
		index++;
	}
}
