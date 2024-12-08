/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:12:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 18:49:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_each_el(char el, t_game *game)
{
	static int	count_p;
	static int	count_e;

	if (!count_p)
		count_p = 0;
	if (!count_e)
		count_e = 0;
	if (el == 'P')
	{
		game->player++;
		count_p++;
	}
	if (el == 'P' && count_p > 1)
		return (0);
	if (el == 'E')
	{
		count_e++;
		game->exit++;
	}
	if (el == 'E' && count_p > 1)
		return (0);
	if (game->exit == 0 || game->exit > 1)
		return (0);
	return (1);
}

static int	check_els(t_game *game)
{
	int	index;
	int	s_index;

	index = 0;
	while (game->map[index] != NULL)
	{
		s_index = 0;
		while (game->map[index][s_index] != '\0')
		{
			if (!check_each_el(game->map[index][s_index], game))
				return (0);
			if (game->map[index][s_index] == 'P')
			{
				game->player_x = index;
				game->player_y = s_index;
			}
			if (game->map[index][s_index] == 'C')
				game->collectible++;
			s_index++;
		}
		index++;
	}
	if (game->collectible == 0)
		return (0);
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	int	index;
	int	s_index;

	index = 0;
	while (map[index] != NULL)
	{
		s_index = 0;
		if (index == 0 || map[index + 1] == NULL)
		{
			while (map[index][s_index] != '\n'
				&& map[index][s_index] != '\0')
			{
				if (map[index][s_index] != '1')
					return (0);
				s_index++;
			}
		}
		else if (map[index][0] != '1' || map[index][length - 2] != '1')
			return (0);
		index++;
	}
	return (1);
}

static int	is_rectangular(char **map)
{
	int	index;
	int	length;

	length = ft_strlen(map[0]);
	index = 0;
	while (map[index] != NULL)
	{
		if (length != ft_strlen(map[index]))
			return (0);
		index++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!is_rectangular(game->map))
		return (ft_putstr_fd_0("The map isn't rectangular.\n", 2));
	if (!is_surrounded_by_walls(game->map))
		return (ft_putstr_fd_0("The map isn't surrounded by walls.\n", 2));
	if (!check_els(game->map, game))
		return (ft_putstr_fd_0("There is/are invalid els on the map.\n", 2));
	if (!check_cosplay(game->player))
		return (ft_putstr_fd_0("There isn't a player or collectibles.\n", 2));
	return (1);
}
