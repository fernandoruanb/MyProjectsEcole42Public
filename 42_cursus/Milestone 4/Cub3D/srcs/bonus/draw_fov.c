/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:07:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 21:07:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	new_position_px_py(t_game *game, double *px, double *py)
{
	*px = (game->width / 2) + game->offset_x;
	*py = (game->heigth / 2) + game->offset_y;
}

static void	draw_new_radius_right(t_game *game)
{
	int		index;
	double	px;
	int		map_x;
	int		map_y;
	double	py;

	index = 0;
	new_position_px_py(game, &px, &py);
	while (index < 1000)
	{
		map_x = px / TILE_SIZE;
		map_y = py / TILE_SIZE;
		if (px < 0 || py < 0
			|| map_y >= game->heigth / TILE_SIZE
			|| map_x >= (int)ft_strlen(game->true_game_map[map_y]))
			break ;
		if (game->true_game_map[map_y][map_x] == '1'
			|| game->true_game_map[map_y][map_x] == ' ')
			break ;
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win, px - game->offset_x,
			py - game->offset_y, COLOUR_DEFAULT);
		px += game->dir_right_x;
		py += game->dir_right_y;
		index++;
	}
}

static void	draw_new_radius_left(t_game *game)
{
	int		index;
	double	px;
	int		map_x;
	int		map_y;
	double	py;

	index = 0;
	new_position_px_py(game, &px, &py);
	while (index < 1000)
	{
		map_x = px / TILE_SIZE;
		map_y = py / TILE_SIZE;
		if (px < 0 || py < 0
			|| map_y >= game->heigth / TILE_SIZE
			|| map_x >= (int)ft_strlen(game->true_game_map[map_y]))
			break ;
		if (game->true_game_map[map_y][map_x] == '1'
			|| game->true_game_map[map_y][map_x] == ' ')
			break ;
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win, px - game->offset_x,
			py - game->offset_y, COLOUR_DEFAULT);
		px += game->dir_left_x;
		py += game->dir_left_y;
		index++;
	}
}

void	draw_fov(t_game *game)
{
	game->angle_left = game->angle - VISUAL_CAMP;
	game->angle_right = game->angle + VISUAL_CAMP;
	game->dir_left_x = cos(game->angle_left);
	game->dir_left_y = sin(game->angle_left);
	game->dir_right_x = cos(game->angle_right);
	game->dir_right_y = sin(game->angle_right);
	draw_new_radius_left(game);
	draw_new_radius_right(game);
}
