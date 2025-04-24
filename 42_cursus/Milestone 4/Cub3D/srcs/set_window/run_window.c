/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/24 17:47:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_no_event(void)
{
	return (0);
}

static void	update_dir_x_y(t_game *game, int pos, char c)
{
	if (c == 'x')
	{
		if (game->offset_x < pos)
			game->dir_x = 1;
		else
			game->dir_x = -1;
		game->dir_y = 0;
	}
	else if (c == 'y')
	{
		if (game->offset_y < pos)
			game->dir_y = 1;
		else
			game->dir_y = -1;
		game->dir_x = 0;
	}
	game->angle = atan2(game->dir_y, game->dir_x);
}

static void	check_the_pos(int pos, t_game *game, char c)
{
	int	px;
	int	py;
	int	map_x;
	int	map_y;

	px = game->offset_x + (game->width / 2);
	py = game->offset_y + (game->heigth / 2);
	if (c == 'x')
		px = pos + (game->width / 2);
	if (c == 'y')
		py = pos + (game->heigth / 2);
	map_x = px / TILE_SIZE;
	map_y = py / TILE_SIZE;
	if (game->true_game_map[map_y][map_x] != '1')
	{
		update_dir_x_y(game, pos, c);
		if (c == 'x')
			game->offset_x = pos;
		else if (c == 'y')
			game->offset_y = pos;
	}
}

static int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		destroy(game);
	if (key == 97)
		check_the_pos(game->offset_x - TILE_SIZE, game, 'x');
	if (key == 119)
		check_the_pos(game->offset_y - TILE_SIZE, game, 'y');
	if (key == 100)
		check_the_pos(game->offset_x + TILE_SIZE, game, 'x');
	if (key == 115)
		check_the_pos(game->offset_y + TILE_SIZE, game, 'y');
	if (key == 65361 || key == 65363)
		update_angle_dir_x_y(game, key);
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win);
	game->min_row = game->offset_y / TILE_SIZE;
	game->min_col = game->offset_x / TILE_SIZE;
	minimap(game);
	return (0);
}

void	run_window(t_game *game)
{
	if (!game)
		return ;
	mlx_loop_hook(game->mlx.mlx_ptr, &handle_no_event, NULL);
	mlx_hook(game->mlx.win, 17, 0, &destroy, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, &handle_input, game);
	minimap(game);
	mlx_loop(game->mlx.mlx_ptr);
}
