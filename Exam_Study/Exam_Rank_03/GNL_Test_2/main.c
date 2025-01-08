/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:17:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 10:54:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	char	*line;

	if (argc < 2)
		return (1);
	if (argc > 2)
		return (1);
	file_descriptor = open(argv[1], O_RDONLY);
	line = get_next_line(file_descriptor);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(file_descriptor);
	}
	if (file_descriptor > 2)
		close(file_descriptor);
	return (0);
}
