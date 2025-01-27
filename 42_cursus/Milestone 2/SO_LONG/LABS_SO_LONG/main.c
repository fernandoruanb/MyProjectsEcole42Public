/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:51:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 11:02:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!render_map(&game))
	{
		ft_putstr_fd_1("Error rendering the map.\n", 2);
		free_game(&game);
	}
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, free_game, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
