/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 16:00:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**fill_map(char **map, int lines, int fd, t_game *game)
{
	int	index;

	index = 0;
	while (index < lines)
	{
		map[index] = get_next_line(fd);
		if (!map[index])
		{
			close(fd);
			free_game(game);
		}
		index++;
	}
	free(get_next_line(fd));
	free(get_next_line(fd));
	close(fd);
	return (map);
}

static int	count_lines(int file_descriptor)
{
	char	*line;
	int		lines;

	lines = 0;
	line = get_next_line(file_descriptor);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			break ;
		}
		free(line);
		lines++;
		line = get_next_line(file_descriptor);
	}
	return (lines);
}

char	**read_map(char *filename, t_game *game)
{
	char	**map;
	int		file_descriptor;
	int		lines;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("There was a mistake opening file\n", 2));
	lines = count_lines(file_descriptor);
	close(file_descriptor);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("There was a mistake reopen file.\n", 2));
	map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (ft_putstr_fd_n("Error allocating memory to map.\n", 2));
	map = fill_map(map, lines, file_descriptor, game);
	if (!map)
		return (ft_putstr_fd_n("Error fill array!\n", 2));
	map[lines] = NULL;
	close(file_descriptor);
	return (map);
}
