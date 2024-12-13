/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:58:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 16:51:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_other_things(t_game *game)
{
	int	index;

	index = 0;
	if (game->map)
	{
		while (game->map[index])
		{
			free(game->map[index]);
			index++;
		}
		free(game->map);
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	game->map = NULL;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
}

int	free_game(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game)
		check_other_things(game);
	if (game)
	{
		game->player_img = NULL;
		game->floor_img = NULL;
		game->collectible_img = NULL;
		game->exit_img = NULL;
		game->wall_img = NULL;
	}
	exit(0);
	return (0);
}
