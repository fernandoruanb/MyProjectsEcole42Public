/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:50:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/14 08:54:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;

	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error opening file!\n", 20);
		return (1);
	}
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(file_descriptor);
	return (0);
}
