/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:30:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/11 15:45:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_tile(int x, int y, t_game *game)
{
	void	*img;

	img = NULL;
	if (game->map[x][y] == 'E')
		img = game->exit_img;
	else if (game->map[x][y] == 'C')
		img = game->collectible_img;
	else if (game->map[x][y] == '0')
		img = game->floor_img;
	else if (game->map[x][y] == 'P')
		img = game->player_img;
	else if (game->map[x][y] == '1')
		img = game->wall_img;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img, x * TILE_SIZE, y * TILE_SIZE);
	if (!img)
		return (0);
	return (1);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x] != NULL)
	{
		y = 0;
		while (game->map[x][y] != '\0')
		{
			if (!render_tile(x, y, game))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}