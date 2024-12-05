/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:16:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 19:02:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game->map[x][y] == '1')
		img = game->wall_img;
	else if (game->map[x][y] == '0')
		img = game->floor_img;
	else if (game->map[x][y] == 'E')
		img = game->exit_img;
	else if (game->map[x][y] == 'P')
		img = game->player_img;
	else if (game->map[x][y] == 'C')
		img = game->collectible_img;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(char **map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			render_tile(game, x, y);
			y++;
		}
		x++;
	}
}
