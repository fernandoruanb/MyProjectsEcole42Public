/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:44:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 17:39:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_countables(t_game *game)
{
	game->moves = 0;
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	game->mlx_flag = 0;
	game->win_flag = 0;
	game->floor_flag = 0;
	game->wall_flag = 0;
	game->exit_flag = 0;
	game->player_flag = 0;
	game->collectible_flag = 0;
}

int	init_game(t_game *game, char *map_file)
{
	init_countables(game);
	game->map = read_map(map_file, game);
	if (!game->map || !validate_map(game->map, game))
		return (ft_putstr_fd_0("Invalid map file.\n", 2));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_putstr_fd_0("Error! Wrong connection MLX\n.", 2));
	game->mlx_flag = 1;
	game->width = ft_strlen(game->map[0]) - 1;
	if (game->width > 30)
		return (ft_putstr_fd_0("Map is so big! Width!\n", 2));
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	if (game->height > 16)
		return (ft_putstr_fd_0("Map is so big! Height!\n", 2));
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (ft_putstr_fd_0("Error opening MLX window.\n", 2));
	game->win_flag = 1;
	if (!load_textures(game))
		return (ft_putstr_fd_0("Error loading textures\n", 2));
	return (1);
}
