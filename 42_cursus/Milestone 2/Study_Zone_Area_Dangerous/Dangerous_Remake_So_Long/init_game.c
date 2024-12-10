/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:22:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 13:06:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_countable_variables(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->move = 0;
}

int	init_game(char *filename, t_game *game)
{
	initialize_countable_variables(game);
	game->map = read_map(filename, game);
	if (!game->map || !validate_map(game))
		return (ft_putstr_fd_1("Error reading or validating map\n", 2));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_putstr_fd_1("Error connecting to MiniLibx", 2));
	game->width = ft_strlen(game->map[0]) - 1;
	if (game->width > 30)
		return (ft_putstr_fd_1("Extreme width! Invalid map.\n", 2));
	game->height = 0;
	while (game->map[game->height] != NULL)
		game->height++;
	if (game->height > 16)
		return (ft_putstr_fd_1("Extreme height! Invalid map!\n", 2));
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (ft_putstr_fd_1("Error creating a window to your game.\n", 2));
	if (!load_textures(game))
		return (ft_putstr_fd_1("Error loading textures.\n", 2));
	return (1);
}
