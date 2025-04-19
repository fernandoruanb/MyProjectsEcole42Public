/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:26:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 14:05:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_true_game_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		free(game->true_game_map[index]);
		index++;
	}
	free(game->true_game_map);
	game->true_game_map = NULL;
}

static void	free_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		free(game->maps[index]);
		index++;
	}
	free(game->maps);
}

static void	clear_all_textures(t_game *game)
{
	if (game->no_texture != NULL)
		free(game->no_texture);
	if (game->so_texture != NULL)
		free(game->so_texture);
	if (game->we_texture != NULL)
		free(game->we_texture);
	if (game->ea_texture != NULL)
		free(game->ea_texture);
	if (game->floor_colours)
		free(game->floor_colours);
	if (game->ceiling_colours)
		free(game->ceiling_colours);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_colours = NULL;
	game->ceiling_colours = NULL;
}

int	free_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->maps)
		free_map(game);
	clear_all_textures(game);
	if (game->true_game_map)
		free_true_game_map(game);
	return (0);
}
