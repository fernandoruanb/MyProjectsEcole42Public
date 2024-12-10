/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:24:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 15:33:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_common_variables(t_game *game)
{
	game->move = 0;
	game->exit = 0;
	game->collectible = 0;
	game->player = 0;
}

int	init_game(char *filename, t_game *game)
{
	initialize_common_variables(game);
	game->map = read_map(filename);
	if (!game->map || !validate_map(&game))
		return (ft_putstr_fd_0("Error creating map.\n", 2));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_putstr_fd_0("Error connecting mlx.\n", 2));
	game->width = ft_strlen(game->map[0]);
	if (game->width > 30)
		return (ft_putstr_fd_0("So big width\n", 2));
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	if (game->height > 16)
		return (ft_putstr_fd_0("So big height\n", 2));
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (ft_putstr_fd_0("Error opening window.\n", 2));
	if (!load_textures(game))
		return (ft_putstr_fd_0("Error loading textures.\n", 2));
	return (1);
}
