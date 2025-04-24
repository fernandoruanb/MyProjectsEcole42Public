/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_radius.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:03:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 17:26:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_radius(t_game *game)
{
	int	index;
	double	px;
	int	map_x;
	int	map_y;
	double	py;

	index = 0;
	px = (game->width / 2) + game->offset_x;
	py = (game->heigth / 2) + game->offset_y;
	while (index < 1000)
	{
		map_x = px / TILE_SIZE;
		map_y = py / TILE_SIZE;
		if (px < 0 || py < 0
			|| map_y >= game->heigth / TILE_SIZE
			|| map_x >= (int)ft_strlen(game->true_game_map[map_y]))
			break ;
		if (game->true_game_map[map_y][map_x] == '1')
			break ;
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win, px - game->offset_x,
			py - game->offset_y, COLOUR_DEFAULT);
		px += game->dir_x;
		py += game->dir_y;
		index++;
	}
}
