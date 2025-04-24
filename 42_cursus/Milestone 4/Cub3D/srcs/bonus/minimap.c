/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:04:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 13:29:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	show_the_art_to_godness(t_game *game, int s_y, int s_x, int c)
{
	int	y;
	int	x;

	s_y *= TILE_SIZE;
	s_x *= TILE_SIZE;
	s_y -= game->offset_y;
	s_x -= game->offset_x;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
				s_x + x, s_y + y, c);
			x++;
		}
		y++;
	}
}

static void	draw_the_player(t_game *game)
{
	int	new_player_x_location;
	int	new_player_y_location;
	int	color;
	int	x;
	int	y;

	new_player_x_location = (game->width / 2) - (TILE_SIZE / 4);
	new_player_y_location = (game->heigth / 2) - (TILE_SIZE / 4);
	color = COLOUR_PLAYER;
	y = 0;
	while (y < TILE_SIZE / 2)
	{
		x = 0;
		while (x < TILE_SIZE / 2)
		{
			mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
				x + new_player_x_location, y + new_player_y_location, color);
			x++;
		}
		y++;
	}
	draw_radius(game);
}

void	minimap(t_game *game)
{
	int		index;
	int		count;
	int		color;
	char	c;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count] != '\0')
		{
			c = game->true_game_map[index][count];
			if (c == '1')
				color = COLOUR_WALL;
			else if (c == '0' || c == 'N' || c == 'W' || c == 'E'
				|| c == 'S')
				color = COLOUR_FLOOR;
			if (c == '0' || c == '1' || c == 'N'
				|| c == 'W' || c == 'E' || c == 'S')
				show_the_art_to_godness(game, index, count, color);
			count++;
		}
		index++;
	}
	draw_the_player(game);
}
