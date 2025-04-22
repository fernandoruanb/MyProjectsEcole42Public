/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:21:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:41:03 by fruan-ba         ###   ########.fr       */
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
	if (set_window(game))
		return (0);
	return (1);
}
