/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_true_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:35:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 13:24:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_lines(int index, t_game *game)
{
	int	lines;

	lines = 0;
	while (game->maps[index] != NULL)
	{
		index++;
		lines++;
	}
	return (lines);
}

static int	clear_the_true_map(t_game *game, int index)
{
	int	count;

	count = 0;
	--index;
	while (count < index)
	{
		free(game->true_game_map[count]);
		count++;
	}
	free(game->true_game_map);
	game->true_game_map = NULL;
	return (0);
}

static int	get_the_base(int index, t_game *game)
{
	int	lines;
	int	pos;

	if (game->true_game_map == NULL)
	{
		lines = get_lines(index, game);
		game->true_game_map = (char **)malloc((lines + 1) * sizeof(char *));
		if (!game->true_game_map)
			return (0);
	}
	pos = 0;
	while (game->maps[index] != NULL)
	{
		game->true_game_map[pos] = ft_strdup(game->maps[index]);
		if (!game->true_game_map[pos])
			return (clear_the_true_map(game, index));
		pos++;
		index++;
	}
	game->true_game_map[pos] = NULL;
	return (1);
}

int	get_true_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& ft_strncmp(game->maps[index], "NO", 2) != 0
			&& ft_strncmp(game->maps[index], "SO", 2) != 0
			&& ft_strncmp(game->maps[index], "WE", 2) != 0
			&& ft_strncmp(game->maps[index], "EA", 2) != 0
			&& ft_strncmp(game->maps[index], "\n", 1) != 0
			&& ft_strncmp(game->maps[index], "F", 1) != 0
			&& ft_strncmp(game->maps[index], "C", 1) != 0)
		{
			if (!get_the_base(index, game))
				return (0);
			return (1);
		}
		index++;
	}
	return (1);
}
