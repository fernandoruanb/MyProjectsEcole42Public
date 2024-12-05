/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:27:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 12:32:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
