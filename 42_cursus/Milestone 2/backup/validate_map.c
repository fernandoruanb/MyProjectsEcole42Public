/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:44:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/06 18:42:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_each_el(char el)
{
	static int	count_p;
	static int	count_e;
	char		*set;

	if (!count_p)
		count_p = 0;
	if (!count_e)
		count_e = 0;
	set = "PCE01\n";
	if (el == 'P')
		count_p++;
	if (el == 'P' && count_p > 1)
		return (0);
	if (el == 'E')
		count_e++;
	if (el == 'E' && count_e > 1)
		return (0);
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
			if (!check_each_el(map[index][s_index]))
				return (ft_putstr_fd_0("Invalid element!\n", 2));
			if (map[index][s_index] == 'P')
			{
				game->player_x = index;
				game->player_y = s_index;
			}
			if (map[index][s_index] == 'C')
				game->collectible++;
			s_index++;
		}
		index++;
	}
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
		return (ft_putstr_fd_0("There is/are invalid els on map.\n", 2));
	return (1);
}
