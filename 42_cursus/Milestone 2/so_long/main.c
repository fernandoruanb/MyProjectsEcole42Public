/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:51:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/03 17:59:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
	{
		ft_putstr_fd("Número de argumentos inválido.\n", 2);
		ft_putstr_fd("Informe um argumento como: ./so_long <mapa.ber>\n", 2);
		return (EXIT_FAILURE);
	}
	if (!init_game(&game, argv[1]))
	{
		ft_putstr_fd("Erro na inicialização. Entrada inválida.\n", 2);
		return (EXIT_FAILURE);
	}
	render_map(&game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (EXIT_SUCCESS);
}
