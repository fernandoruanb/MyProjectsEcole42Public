/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:10:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 18:12:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **map_copy)
{
	int	index;

	index = 0;
	while (map_copy[index])
	{
		free(map_copy[index]);
		index++;
	}
	free(map_copy);
}

static void	start_test(char **map_copy, int x, int y, t_game *game)
{
	if (x >= game->lines || y >= game->length || x < 0
		|| y < 0)
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'V'
		|| map_copy[x][y] == 'E')
		return ;
	if (map_copy[x][y] == 'C')
	{
		if (map_copy[x][y] == 'C')
			game->collectibles--;
		map_copy[x][y] = 'V';
	}
	if (map_copy[x][y] == '0')
		map_copy[x][y] = 'V';
	start_test(map_copy, x + 1, y, game);
	start_test(map_copy, x - 1, y, game);
	start_test(map_copy, x, y + 1, game);
	start_test(map_copy, x, y - 1, game);
}

int	check_game(char **map_copy, t_game *game)
{
	if (game->collectibles != 0 || game->exit_t != 1)
	{
		free_map_copy(map_copy);
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}

int	flood_fill(t_game *game)
{
	char	**map_copy;

	game->exit_t = 0;
	game->length = 0;
	while (game->map[0][game->length] != '\n'
		&& game->map[0][game->length] != '\0')
		game->length++;
	game->lines = 0;
	while (game->map[game->lines])
		game->lines++;
	map_copy = get_map(game);
	if (map_copy == NULL)
		return (0);
	game->x = game->player_x;
	game->y = game->player_y;
	game->collectibles = game->collectible;
	start_test(map_copy, game->x, game->y, game);
	free_map_copy(map_copy);
	map_copy = get_map(game);
	if (map_copy == NULL)
		return (0);
	start_test_exit(map_copy, game->x, game->y, game);
	if (!check_game(map_copy, game))
		return (0);
	return (1);
}
