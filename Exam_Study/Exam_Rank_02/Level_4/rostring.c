/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:24:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/27 16:41:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostring(const char *str, int index);

int	main(int argc, char **argv)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while ((argv[1][index]) && (argv[1][index] == ' '
		|| argv[1][index] == '\t'))
		index++;
	count = index;
	while ((argv[1][index]) && (argv[1][index] != ' '
		&& argv[1][index] != '\t'))
		index++;
	rostring(argv[1], index);
	while (count < index)
	{
		write(1, &argv[1][count], 1);
		count++;
	}
	write(1, "\n", 1);
	return (0);
}

void	rostring(const char *str, int index)
{
	while (str[index] != '\0')
	{
		while ((str[index]) && (str[index] == ' '
			|| str[index] == '\t'))
			index++;
		while ((str[index]) && str[index] != ' '
			&& str[index] != '\t')
			{
				write(1, &str[index], 1);
				index++;
			}
		if (str[index] != '\0')
			write(1, " ", 1);
	}
}
