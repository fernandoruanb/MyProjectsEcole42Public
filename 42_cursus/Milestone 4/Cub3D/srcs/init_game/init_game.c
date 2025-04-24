/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:21:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 18:42:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_game(const char *filename, t_game *game)
{
	init_all_things(game);
	game->maps = get_map(filename);
	if (!check_security_on_map(game))
		return (0);
	if (!game->maps || !get_map_textures(game))
		return (0);
	if (!is_valid_map(game))
		return (0);
	if (!get_width_heigth(game))
		return (0);
	if (!rgb_to_rrggbb(game))
		return (ft_putendl_fd_0("Error: converting to RRGGBB", 2));
	if (!game->rrggbb_floor || !game->rrggbb_ceiling)
		return (ft_putendl_fd_0("Error: hole on rrggbb", 2));
	game->max_col = game->heigth / TILE_SIZE;
	game->max_row = game->width / TILE_SIZE;
	if (set_window(&game->mlx))
		return (0);
	init_map(&game->map, game);
	return (1);
}
