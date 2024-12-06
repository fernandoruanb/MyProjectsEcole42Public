/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:44:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/06 18:20:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_file)
{
	game->moves = 0;
	game->collectible = 0;
	game->map = read_map(map_file);
	if (!game->map || !validate_map(game->map, game))
		return (ft_putstr_fd_0("Invalid map file.\n", 2));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_putstr_fd_0("Error! Wrong connection MLX\n.", 2));
	game->width = ft_strlen(game->map[0]) - 1;
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (ft_putstr_fd_0("Error opening MLX window.\n", 2));
	if (!load_textures(game))
		return (ft_putstr_fd_0("Error loading textures\n", 2));
	return (1);
}
