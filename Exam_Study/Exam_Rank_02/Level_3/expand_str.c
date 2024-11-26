/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:24:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 10:39:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;
	int	count;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	while ((argv[1][index]) && (argv[1][index] == ' '
		|| argv[1][index] == '\t'))
		index++;
	while (argv[1][index] != '\0')
	{
		count = 3;
		if ((argv[1][index] == ' ' || argv[1][index] == '\t')
			&& argv[1][index + 1] != ' '
			&& argv[1][index + 1] != '\t'
			&& argv[1][index + 1] != '\0')
		{
			while (count)
			{
				write(1, " ", 1);
				count--;
			}
		}
		else if (argv[1][index] != ' ' && argv[1][index] != '\t')
			write(1, &argv[1][index], 1);
		index++;
	}
	return (0);
}
