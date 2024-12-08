/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:12:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 09:00:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_heap_variables(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->player_img = NULL;
	game->wall_img = NULL;
	game->collectible_img = NULL;
	game->exit_img = NULL;
	game->floor_img = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_putstr_fd_1("How to use: ./so_long <map.ber>\n", 2));
	if (!init_game(argv[1], &game))
	{
		initialize_heap_variables(&game);
		ft_putstr_fd_1("Inicialization Error.\n", 2);
		free_game(game);
	}
	if (!render_map(&game))
	{
		ft_putstr_fd_1("Error rendering the map.\n", 2);
		free_game(game);
	}
	mlx_key_hook(game.win_ptr, key_press, game);
	mlx_hook(game.win_ptr, 17, 0, free_game, game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
}
