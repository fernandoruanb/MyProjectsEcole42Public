/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:40:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 12:57:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char c);

int	main(int argc, char **argv)
{
	char	character;
	int		index;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		if ((argv[1][index] < 'a' && argv[1][index] > 'z')
			&& (argv[1][index] < 'A' && argv[1][index] > 'Z'))
			write(1, &argv[1][index], 1);
		rot_13(argv[1][index]);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}

void	rot_13(char c)
{
	char	*alphabet_l;
	char	*alphabet_u;
	int		index;

	alphabet_l = "abcdefghijklmnopqrstuvwxyz";
	alphabet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	index = 0;
	while (alphabet_l[index] != '\0')
	{
		if (alphabet_l[index] == c)
			write(1, &alphabet_l[(index + 13) % 26], 1);
		index++;
	}
	index = 0;
	while (alphabet_u[index] != '\0')
	{
		if (alphabet_u[index] == c)
			write(1, &alphabet_u[(index + 13) % 26], 1);
		index++;
	}
}
