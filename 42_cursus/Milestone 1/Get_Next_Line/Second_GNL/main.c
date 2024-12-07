/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:50:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/07 18:49:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	**map;
	int	index;
	int	lines;
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
	lines = 0;
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", line);
		lines++;
		free(line);
	}
	printf("%d\n", lines);
	close(file_descriptor);
	map = (char **)ft_calloc_v2(lines + 1, sizeof(char *));
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(2, "Error to reopen file.\n", 22);
		return (1);
	}
	index = 0;
	while (index < lines)
		map[index++] = get_next_line(file_descriptor);
	map[lines] = NULL;
	index = 0;
	while (map[index] != NULL)
	{
		printf("Array[%d]: %s", index, map[index]);
		index++;
	}
	close(file_descriptor);
	return (0);
}
