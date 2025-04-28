/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:09:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 17:23:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	new_position_px_py(t_game *g, double *px, double *py, double *s)
{
	*px = (g->width / 2) + g->offset_x;
	*py = (g->heigth / 2) + g->offset_y;
	g->px_start = *px;
	g->py_start = *py;
	g->dir_get_x = cos(g->angle_k);
	g->dir_get_y = sin(g->angle_k);
	*s = 1.0 / fmax(fabs(g->dir_get_x), fabs(g->dir_get_y));
}

static void	get_radius(t_game *game)
{
	double	px;
	int		map_x;
	int		map_y;
	double	py;
	double	step;

	new_position_px_py(game, &px, &py, &step);
	while (1)
	{
		map_x = px / TILE_SIZE;
		map_y = py / TILE_SIZE;
		if (px < 0 || py < 0 || map_y >= game->heigth_map
			|| map_x >= (int)ft_strlen(game->true_game_map[map_y]))
			break ;
		if (game->true_game_map[map_y][map_x] == '1'
			|| game->true_game_map[map_y][map_x] == ' ')
			break ;
		px += game->dir_get_x * step;
		py += game->dir_get_y * step;
	}
	game->target_x = map_x;
	game->dir_x_c = px - game->px_start;
	game->dir_y_c = py - game->py_start;
	get_distance(game, 4);
}

static void	draw_column(t_game *game, int x)
{
	int	y;

	init_all_3d(game);
	y = game->draw_3d_center_s;
	while (y < game->draw_3d_center_e)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			400 + x, 400 + y, COLOUR_DEFAULT);
		y++;
	}
}

void	render_the_3d(t_game *game)
{
	int		x;
	double	new_x;

	x = 0;
	while (x < game->width)
	{
		new_x = 2.0 * x / (game->width - 1.0) - 1.0;
		game->angle_k = game->angle + atan(new_x * tan(VISUAL_CAMP / 2));
		get_radius(game);
		draw_ceiling(game, x);
		draw_column(game, x);
		draw_floor(game, x);
		x++;
	}
}
