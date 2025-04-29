/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:02:35 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/29 11:31:58 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (drawstr("Error: mlx error\n", 2, 1));
	return (0);
}

int	set_window(t_mlx *mlx)
{
	int	win_w;
	int	win_h;

	if (!mlx || init_mlx(mlx))
		return (1);
	win_w = 1920;
	win_h = 1080;
	mlx->win = mlx_new_window(mlx->mlx_ptr, win_w, win_h, "cub3d");
	if (!mlx->win)
		return (drawstr("Error: Couldn't open the window\n", 2, 1));
	render(mlx);
	return (0);
}
