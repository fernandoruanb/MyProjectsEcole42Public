/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:03:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 18:21:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game->map[y][x] == 'P')
		img = game->player_img;
	else if (game->map[y][x] == 'C')
		img = game->collectible_img;
	else if (game->map[y][x] == 'E')
		img = game->exit_img;
	else if (game->map[y][x] == '0')
		img = game->floor_img;
	else if (game->map[y][x] == '1')
		img = game->wall_img;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[index] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
