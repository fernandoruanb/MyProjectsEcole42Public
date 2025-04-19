/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_true_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:35:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 10:35:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_lines(int index, t_game *game)
{
	int	lines;

	lines = 0;
	while (game->maps[index] != NULL)
	{
		lines++;
		index++;
	}
	return (lines);
}

static int	clear_the_true_map(t_game *game, int index, int pos)
{
	int	count;

	count = 0;
	--index;
	while (count < index)
	{
		free(game->true_map[count]);
		count++;
	}
	free(game->true_map);
	game->true_map = NULL;
	return (0);
}

static int	get_the_base(int index, t_game *game)
{
	int	lines;
	int	pos;

	lines = get_lines(index, game);
	game->true_map = (char **)malloc((lines + 1) * sizeof(char *));
	if (!game->true_map)
		return (0);
	pos = 0;
	while (game->maps[index] != NULL)
	{
		game->true_map[pos] = ft_strdup(game->maps[index]);
		if (!game->true_map[pos])
			return (clear_the_true_map(game, index, pos));
		pos++;
		index++;
	}
	return (1);
}

int	get_true_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& game->maps[index][0] != 'N'
			&& game->maps[index][0] != 'S'
			&& game->maps[index][0] != 'W'
			&& game->maps[index][0] != 'E')
		{
			if (!get_the_base(index, game))
				return (0);
		}
		index++;
	}
	return (1);
}
