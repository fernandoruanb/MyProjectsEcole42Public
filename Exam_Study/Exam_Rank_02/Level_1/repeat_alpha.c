/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:40:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 11:57:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	repeat_alpha(char c);

int	main(int argc, char **argv)
{
	int	index;
	int	times;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		times = repeat_alpha(argv[1][index]);
		if (times == -1)
			write(1, &argv[1][index], 1);
		while (times > 0)
		{
			write(1, &argv[1][index], 1);
			times--;
		}
		index++;
	}
	write(1, "\n", 1);
	return (0);
}

int	repeat_alpha(char c)
{
	int		index;
	char	*alphabet_l;
	char	*alphabet_u;

	alphabet_l = "abcdefghijklmnopqrstuvwxyz";
	alphabet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	index = 0;
	while (alphabet_l[index] != '\0')
	{
		if (alphabet_l[index] == c)
			return (index + 1);
		index++;
	}
	index = 0;
	while (alphabet_u[index] != '\0')
	{
		if (alphabet_u[index] == c)
			return (index + 1);
		index++;
	}
	return (-1);
}
