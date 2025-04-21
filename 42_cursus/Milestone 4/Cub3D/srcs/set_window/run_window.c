/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/21 13:57:06 by jopereir         ###   ########.fr       */
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
	return (0);
}

void	run_window(t_game *game)
{
	if (!game)
		return ;
	mlx_loop_hook(game->mlx, &handle_no_event, NULL);
	mlx_key_hook(game->win, &handle_input, game);
	mlx_hook(game->win, 17, 0, &destroy, game);
	mlx_loop(game->mlx);
}
