/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:44:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 13:47:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_each_el(char el, t_game *game, int x, int y)
{
	char		*set;

	set = "PCE01\n";
	if (el == 'P')
		game->player++;
	if (el == 'P' && game->player > 1)
		return (ft_putstr_fd_0("Too many players!\n", 2));
	if (el == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	if (el == 'E')
		game->exit++;
	if (el == 'E' && game->exit > 1)
		return (ft_putstr_fd_0("Too many exits.\n", 2));
	if (el == 'C')
		game->collectible++;
	if (!ft_strchr_v3(set, el))
		return (0);
	return (1);
}

static int	check_els(char **map, t_game *game)
{
	int		index;
	int		s_index;

	index = 0;
	while (map[index] != NULL)
	{
		s_index = 0;
		while (map[index][s_index] != '\0')
		{
			if (!check_each_el(map[index][s_index], game, index, s_index))
				return (ft_putstr_fd_0("Invalid element!\n", 2));
			s_index++;
		}
		index++;
	}
	if (game->player == 0)
		return (ft_putstr_fd_0("There aren't players on the map.\n", 2));
	if (game->collectible == 0)
		return (ft_putstr_fd_0("There aren't collectibles on the map.\n", 2));
	if (game->exit == 0)
		return (ft_putstr_fd_0("There isn't an exit on the map!\n", 2));
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	size_t	index;
	size_t	length;
	size_t	letter;

	index = 0;
	length = ft_strlen(map[index]);
	while (map[index] != NULL)
	{
		letter = 0;
		if (index == 0 || map[index + 1] == NULL)
		{
			while (map[index][letter] != '\0' && map[index][letter] != '\n')
			{
				if (map[index][letter] != '1')
					return (0);
				letter++;
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
	size_t	length;
	size_t	lines;
	size_t	index;

	length = ft_strlen(map[0]);
	lines = 0;
	while (map[lines] != NULL)
		lines++;
	index = 0;
	while (index < lines)
	{
		if (length != ft_strlen(map[index]))
			return (0);
		index++;
	}
	return (1);
}

int	validate_map(char **map, t_game *game)
{
	if (!is_rectangular(map))
		return (ft_putstr_fd_0("The map is not rectangular.\n", 2));
	if (!is_surrounded_by_walls(map))
		return (ft_putstr_fd_0("The map isn't surrounded by walls.\n", 2));
	if (!check_els(map, game))
		return (ft_putstr_fd_0("You need to check the elements.\n", 2));
	if (!flood_fill(game))
		return (ft_putstr_fd_0("The map isn't playable.\n", 2));
	return (1);
}
