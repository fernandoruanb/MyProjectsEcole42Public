/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:46:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 13:11:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill_map(char **map, int lines, int fd, t_game *game)
{
	int	index;

	index = 0;
	while (index < lines)
	{
		map[index++] = get_next_line(fd);
		if (!map[index])
		{
			while (--index > 0)
				free(map[index]);
			free(game->map);
			close(fd);
			ft_putstr_fd_n("Error during filling the map.\n", 2);
			free_game(game);
		}
		index++;
	}
	free(get_next_line(fd));
	return (map);
}

static int	count_lines(int file_descriptor)
{
	int		lines;
	char	*temp_line;

	temp_line = get_next_line(file_descriptor);
	while (temp_line != NULL)
	{
		lines++;
		free(temp_line);
		temp_line = get_next_line(file_descriptor);
	}
	free(get_next_line(file_descriptor));
	return (lines);
}

char	**read_map(char *filename, t_game *game)
{
	int		file_descriptor;
	int		lines;
	char	**map;
	int		index;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_0("Error opening file.\n", 2));
	lines = count_lines(file_descriptor);
	close(file_descriptor);
	map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (ft_putstr_fd_n("Error alocating memory to map.\n", 2));
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("Error reopening file.\n", 2));
	map = fill_map(map, lines, file_descriptor, game);
	if (!map)
		return (ft_putstr_fd_n("Error filling the map.\n", 2));
	return (map);
}
