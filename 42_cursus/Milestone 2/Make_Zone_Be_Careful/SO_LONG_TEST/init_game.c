/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:16:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/11 09:33:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_common_variables(t_game *game)
{
	game->moves = 0;
	game->collectibles = 0;
	game->players = 0;
	game->exits = 0;
}

int	init_game(char *filename, t_game *game)
{
	initialize_common_variables(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_putstr_fd_1("Error connection with MLX\n", 2));
	game->map = read_map(filename);
	if (!game->map || !validate_map(&game))
		return (ft_putstr_fd_1("Error reading or validating map.\n", 2));
	game->width = ft_strlen(game->map[0]) - 1;
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (ft_putstr_fd_1("Error opening the window.\n", 2));
	if (!load_textures)
		return (ft_putstr_fd_1("Error loading textures.\n", 2));
	return (1);
}
