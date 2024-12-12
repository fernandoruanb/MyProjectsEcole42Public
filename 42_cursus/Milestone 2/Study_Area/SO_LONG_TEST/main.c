/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:05:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/11 09:16:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_heap_variables(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->player_img = NULL;
	game->exit_img = NULL;
	game->floor_img = NULL;
	game->wall_img = NULL;
	game->collectible_img = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_putstr_fd_1("How to use: ./so_long <map.ber>\n", 2));
	if (!init_game(argv[1], &game))
	{
		initialize_heap_variables(&game);
		ft_putstr_fd_1("Initialization error!\n", 2);
		free_game(&game);
	}
	if (!render_map(&game))
		return (ft_putstr_fd_1("Error rendering the map.\n", 2));
	mlx_key_hook(game.win_ptr, keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, free_game, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
