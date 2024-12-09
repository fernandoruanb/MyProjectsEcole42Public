/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:49:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 13:08:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_tile(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game->map[x][y] == 'P')
		img = game->player_img;
	else if (game->map[x][y] == 'C')
		img = game->collectible_img;
	else if (game->map[x][y] == '0')
		img = game->floor_img;
	else if (game->map[x][y] == '1')
		img = game->wall_img;
	else if (game->map[x][y] == 'E')
		img = game->exit_img;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		x * TILE_SIZE, y * TILE_SIZE);
	if (!mlx_put_image_to_window)
		return (ft_putstr_fd_0("Error impressing images.\n", 2));
	return (1);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (!render_tile(game, x, y))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
