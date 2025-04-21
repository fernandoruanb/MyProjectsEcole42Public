/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:02:35 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/21 13:58:06 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (drawstr("Error: mlx error\n", 2, 1));
	return (0);
}

int	set_window(t_game *game)
{
	int	win_w;
	int	win_h;

	if (!game)
		return (1);
	if (init_mlx(game))
		return (1);
	mlx_get_screen_size(game->mlx, &win_w, &win_h);
	game->win = mlx_new_window(game->mlx, win_w, win_h, "cub3d");
	if (!game->win)
		return (drawstr("Error: Couldn't open the window\n", 2, 1));
	render(game);
	return (0);
}
