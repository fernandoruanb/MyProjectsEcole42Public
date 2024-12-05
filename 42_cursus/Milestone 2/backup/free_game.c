/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:58:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 19:15:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_other_things(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

int	free_game(t_game *game)
{
	int	index;

	if (game->map)
	{
		index = 0;
		while (game->map[index] != NULL)
		{
			free(game->map[index]);
			index++;
		}
		free(game);
	}
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
	check_other_things(game);
	exit(0);
	return (0);
}
