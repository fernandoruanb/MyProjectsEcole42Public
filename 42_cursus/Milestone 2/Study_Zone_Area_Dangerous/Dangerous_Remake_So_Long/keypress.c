/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:31:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 11:26:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_new_map(t_game *game)
{
	if (!render_map(game))
	{
		ft_putstr_0("Error rendering again the map.\n", 2);
		free_game(game);
	}
}

static void	check_win(t_game *game)
{
	if (game->collectible == 0)
	{
		ft_printf("You won the game :D.\n");
		free_game(game);
	}
}

static void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_x][new_y] == '1')
		return ;
	else if (game->map[new_x][new_y] == 'C')
	{
		game->collectible--;
		ft_printf("You need to find %d collectibles", game->collectible);
		game->map[new_x][new_y] == '0';
	}
	if (game->map[new_x][new_y] == 'E')
	{
		if (game->collectible > 0)
			return ;
		check_win(game);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	render_new_map(game);
	return (1);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
}
