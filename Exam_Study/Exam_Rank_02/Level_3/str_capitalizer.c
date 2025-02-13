/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/28 13:50:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	str_capitalizer(char *str);

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (index < argc)
	{
		str_capitalizer(argv[1]);
		write(1, "\n", 1);
		index++;
	}
	return (0);
}

void	str_capitalizer(char *str)
{
	int	index;

	index = 0;
	if (str[index] >= 'a' && str[index] <= 'z')
		str[index] -= 32;
	write(1, &str[index], 1);
	while (str[++index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
		       str[index] += 32;
		if ((str[index] >= 'a' && str[index] <= 'z') && (str[index - 1] == ' '
			|| str[index] == '\t'))
			str[index] -= 32;
		write(1, &str[index], 1);
	}
}
