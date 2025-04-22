/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:50:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 13:00:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_map_copy(char **map)
{
	int	index;

	index = 0;
	while (map[index] != NULL)
	{
		free(map[index]);
		index++;
	}
	free(map);
}

static void	start_test_flood_fill(char **map, int x, int y, t_game *game)
{
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == ' ')
	{
		if (map[x][y] == ' ')
			game->invalid_map = 1;
		return ;
	}
	if (map[x][y] != '1' && map[x][y] != 'V')
		map[x][y] = 'V';
	start_test_flood_fill(map, x + 1, y, game);
	start_test_flood_fill(map, x - 1, y, game);
	start_test_flood_fill(map, x, y + 1, game);
	start_test_flood_fill(map, x, y - 1, game);
}

static char	**emergency_free(char **map, int index)
{
	int	count;

	--index;
	count = 0;
	while (count < index)
	{
		free(map[count]);
		count++;
	}
	free(map);
	return (NULL);
}

static char	**get_map_copy(t_game *game)
{
	int		index;
	int		lines;
	char	**map;

	lines = get_all_lines(game);
	map = (char **)malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		map[index] = ft_strdup(game->true_game_map[index]);
		if (!map[index])
			return (emergency_free(map, index));
		index++;
	}
	map[index] = NULL;
	return (map);
}

int	flood_fill(t_game *game)
{
	char	**map_copy;

	map_copy = get_map_copy(game);
	if (!map_copy)
		return (0);
	start_test_flood_fill(map_copy, game->player_x, game->player_y, game);
	if (game->invalid_map == 1)
	{
		free_map_copy(map_copy);
		return (ft_putendl_fd_0("Error: The player met Hole", 2));
	}
	free_map_copy(map_copy);
	return (1);
}
