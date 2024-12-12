/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:00:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 14:31:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (ft_putstr_fd("File name missing.\n", 2));
	if (!init_game(argv[1], &game))
		return (ft_putstr_fd("Error initialization game.\n", 2));
	render_map(&game);
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, free_game, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
