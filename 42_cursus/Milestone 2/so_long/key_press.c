/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:27:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 16:46:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(char next_tile, t_game *game)
{
	if (next_tile == 'E')
	{
		if (game->collectible == 0)
		{
			ft_printf("Congratulations! You won the game!!! :D\n");
			free_game(game);
		}
	}
}

static void	move_player(t_game *game, int mod_x, int mod_y)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = game->player_x + mod_x;
	new_y = game->player_y + mod_y;
	if (new_y < 0 || new_y >= game->heigth || new_x < 0 || new_x >= game->width)
		return ;
	next_tile = game->map[new_x][new_y];
	if (next_tile == '1')
		return ;
	else if (next_tile == 'C')
	{
		game->collectible--;
		game->map[new_x][new_y] = '0';
		ft_printf("You need to find %d collectibles.\n", game->collectible);
	}
	check_win(next_tile, game);
	return ;
}

void	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_game(&game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, -1, 0);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 1, 0);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, 0, -1);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 0, 1);
}
