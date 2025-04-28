/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/28 18:52:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_no_event(void)
{
	return (0);
}

static int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		destroy(game);
	if (key == 97)
		move_a(game);
	if (key == 119)
		move_w(game);
	if (key == 100)
		move_d(game);
	if (key == 115)
		move_s(game);
	if (key == 65361 || key == 65363)
		update_angle_dir_x_y(game, key);
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win);
	game->min_row = game->offset_y / TILE_SIZE;
	game->min_col = game->offset_x / TILE_SIZE;
	minimap(game);
	render_the_3d(game);
	return (0);
}

void	run_window(t_game *game)
{
	if (!game)
		return ;
	mlx_get_screen_size(game->mlx.mlx_ptr, &game->screen_w, &game->screen_h);
	ft_printf("Screen Width: %d\n", game->screen_w);
	ft_printf("Screen Heigth: %d\n", game->screen_h);
	if (game->width > game->screen_w)
		game->width = game->screen_w;
	if (game->heigth > game->screen_h)
		game->heigth = game->screen_h;
	mlx_loop_hook(game->mlx.mlx_ptr, &handle_no_event, NULL);
	mlx_hook(game->mlx.win, 17, 0, &destroy, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, &handle_input, game);
	minimap(game);
	render_the_3d(game);
	mlx_loop(game->mlx.mlx_ptr);
}
