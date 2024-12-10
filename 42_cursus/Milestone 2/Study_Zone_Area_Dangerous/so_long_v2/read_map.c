/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:34:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 16:00:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill_map(char **map, int fd, int lines, t_game *game)
{
	int	index;

	index = 0;
	while (index < lines)
	{
		map[index] = get_next_line(fd);
		if (!map[index])
		{
			close(fd);
			ft_putstr_fd_n("Error filling map.\n", 2);
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

	line = get_next_line(fd);
	lines = 0;
	while (line != NULL)
	{
		if (line[0] != '\n')
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

char	**read_map(char *filename, t_game *game)
{
	int		lines;
	char	**map;
	int		file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("Error opening the file.\n", 2));
	lines = count_lines(file_descriptor);
	close(file_descriptor);
	map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (ft_putstr_fd_n("Error allocating memory to map.\n", 2));
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("Error reopening the file.\n", 2));
	map = fill_map(map, file_descriptor, lines, game);
	close(file_descriptor);
	if (!map)
		return (ft_putstr_fd_n("Error filling the map.\n", 2));
	return (map);
}
