/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:22:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 14:59:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char *alphabet_l, char *alphabet_u, char letter);

int	main(int argc, char **argv)
{
	char	*alphabet_l;
	char	*alphabet_u;
	int		index;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	alphabet_l = "abcdefghijklmnopqrstuvwxyz";
	alphabet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	index = 0;
	while (argv[1][index] != '\0')
	{
		if ((argv[1][index] < 'a' || argv[1][index] > 'z')
			&& (argv[1][index] < 'A' || argv[1][index] > 'Z'))
			write(1, &argv[1][index], 1);
		rot_13(alphabet_l, alphabet_u, argv[1][index]);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}

void	rot_13(char *alphabet_l, char *alphabet_u, char letter)
{
	int	index;
	int	s_index;

	index = 0;
	s_index = 0;
	while (alphabet_l[index] != letter && alphabet_l[index] != '\0')
		index++;
	if (alphabet_l[index] == letter)
		write(1, &alphabet_l[(index + 13) % 26], 1);
	while (alphabet_u[s_index] != letter && alphabet_u[s_index] != '\0')
		s_index++;
	if (alphabet_u[s_index] == letter)
		write(1, &alphabet_u[(s_index + 13) % 26], 1);
}
