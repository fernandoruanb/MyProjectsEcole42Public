/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:51:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 18:18:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**map;

	if (argc < 2)
		return (ft_putstr_fd("how to use: ./so_long <mapa.ber>.\n", 2));
	if (!init_game(&game, argv[1]))
		return (ft_putstr_fd("Inicialization error.\n", 2));
	map = read_map(argv[1]);
	if (!map)
		return (ft_putstr_fd("Can't open map!\n", 2));
	render_map(map, &game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, free_game, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
