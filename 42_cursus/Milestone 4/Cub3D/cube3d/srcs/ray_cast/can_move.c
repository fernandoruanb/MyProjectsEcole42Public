/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:22:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/28 15:41:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	can_move(t_game *game, double next_x, double next_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(next_x + (game->width / 2)) / TILE_SIZE;
	map_y = (int)(next_y + (game->heigth / 2)) / TILE_SIZE;
	if (game->true_game_map[map_y][map_x] == '1')
		return (0);
	return (1);
}
