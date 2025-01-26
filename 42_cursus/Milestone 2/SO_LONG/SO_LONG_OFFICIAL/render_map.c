/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:16:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 10:08:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_tile(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game->map[y][x] == '1')
		img = game->wall_img;
	else if (game->map[y][x] == '0')
		img = game->floor_img;
	else if (game->map[y][x] == 'E')
		img = game->exit_img;
	else if (game->map[y][x] == 'P')
		img = game->player_img;
	else if (game->map[y][x] == 'C')
		img = game->collectible_img;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img, x * TILE_SIZE, y * TILE_SIZE);
	else if (!img)
		return (ft_putstr_fd_0("Can't open the image.\n", 2));
	return (1);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0'
			&& game->map[y][x] != '\n')
		{
			if (!render_tile(game, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
