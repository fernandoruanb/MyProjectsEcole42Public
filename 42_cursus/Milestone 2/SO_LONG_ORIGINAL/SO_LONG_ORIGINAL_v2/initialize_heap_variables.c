/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_heap_variables.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:57:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 11:01:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_heap_variables(t_game *game)
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
