/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:51:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/07 15:38:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_game_ptrs(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->player_img = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->collectible_img = NULL;
	game->exit_img = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_putstr_fd_1("how to use: ./so_long <map.ber>.\n", 2));
	if (!init_game(&game, argv[1]))
	{
		initialize_game_ptrs(&game);
		free_game(&game);
		return (ft_putstr_fd_1("Inicialization error.\n", 2));
	}
	render_map(game.map, &game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, free_game, &game);
	if (game.mlx_ptr && game.win_ptr && game.map)
		mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
