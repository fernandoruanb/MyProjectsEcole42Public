/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:31:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 12:59:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_putstr_fd("Uso: ./so_long <mapa.ber>\n", 2));
	if (!init_game(&game, argv[1]))
		return (ft_putstr_fd("Erro na inicialização do jogo.\n", 2));
	render_map(&game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
