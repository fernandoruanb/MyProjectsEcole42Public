/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:37:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/11 10:05:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**fill_map(char **map, int fd, int lines, t_game *game)
{
	int	index;

	index = 0;
	while (index < lines)
	{
		map[index++] = get_next_line(fd);
		if (!map[index])
		{
			while (index > 0)
				free(map[--index]);
			ft_putstr_fd_n("Error filling map.\n", 2);
			close(fd);
			free_game(game);
		}
		index++;
	}
	free(get_next_line(fd));
	free(get_next_line(fd));
	return (map);
}

static int	count_lines(int fd)
{
	int		lines;
	char	*line;

	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			break ;
		}
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	return (lines);
}

char	**read_map(char *filename)
{
	int		file_descriptor;
	int		lines;
	char	**map;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("Error reading the file.\n", 2));
	lines = count_lines(file_descriptor);
	close(file_descriptor);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("Error reopening the file.\n", 2));
	map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (ft_putstr_fd_n("Error alocating the map.\n", 2));
	map = fill_map(map, file_descriptor, lines, game);
	if (!map)
		return (ft_putstr_fd_n("Error filling the map.\n", 2));
	map[lines] = NULL;
	close(file_descriptor);
	return (map);
}
