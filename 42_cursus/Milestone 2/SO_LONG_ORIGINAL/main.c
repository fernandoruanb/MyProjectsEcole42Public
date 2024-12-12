/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:51:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 17:52:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_heap_variables(t_game *game)
{
	if (game->mlx_flag != 1)
		game->mlx_ptr = NULL;
	if (game->win_flag != 1)
		game->win_ptr = NULL;
	if (game->player_flag != 1)
		game->player_img = NULL;
	if (game->floor_flag != 1)
		game->floor_img = NULL;
	if (game->wall_flag != 1)
		game->wall_img = NULL;
	if (game->collectible_flag != 1)
		game->collectible_img = NULL;
	if (game->exit_flag != 1)
		game->exit_img = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_putstr_fd_1("how to use: ./so_long <map.ber>.\n", 2));
	if (!init_game(&game, argv[1]))
	{
		initialize_heap_variables(&game);
		ft_putstr_fd_1("Error initializing the game\n", 2);
		free_game(&game);
	}
	render_map(game.map, &game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, free_game, &game);
	if (game.mlx_ptr && game.win_ptr && game.map)
		mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
