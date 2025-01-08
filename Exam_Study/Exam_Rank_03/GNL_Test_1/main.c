/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:05:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/08 09:18:56 by fruan-ba         ###   ########.fr       */
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
	else if (argc > 2)
		return (1);
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
		return (1);
	line = get_next_line(file_descriptor);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(file_descriptor);
	}
	close(file_descriptor);
	return (0);
}
