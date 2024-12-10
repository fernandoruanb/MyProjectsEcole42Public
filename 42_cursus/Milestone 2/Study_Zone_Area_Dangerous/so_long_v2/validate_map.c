/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:02:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 17:46:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_each_el(char el, t_game *game)
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

static int	check_el(t_game *game)
{
	int	index;
	int	s_index;

	while (game->map[index] != NULL)
	{
		while (game->map[index][s_index] != '\0')
		{
			if (!check_each_el(game->map[index][s_index]))
				return (0);
			if (game->map[index][s_index] == 'P')
			{
				player_x = index;
				player_y = s_index;
				game->player++;
			}
			if (game->map[index][s_index] == 'C')
				game->collectible++;
		}
		index++;
	}
	if (game->exit == 0 || game->exit > 1)
		return (0);
	return (1);
}

static int	is_surrounded_by_walls(t_game *game)
{
	int	length;
	int	index;
	int	s_index;

	index = 0;
	length = game->map[0];
	while (game->map[index] != NULL)
	{
		if (index == 0 || game->map[index + 1] == NULL)
		{
			s_index = 0;
			while (game->map[index][s_index] != '\0'
				&& game->map[index][s_index] != '\n')
			{
				if (game->map[index][s_index] != '1')
					return (0);
				s_index++;
			}
		}
		else if (map[index][0] != '1' || map[index][length - 2] != '1')
			return (0);
	}
	return (1);
}

static int	is_rectangular(t_game *game)
{
	int	index;
	int	length;

	length = ft_strlen(game->map[0]);
	index = 0;
	while (game->map[index] != NULL)
	{
		if (length != ft_strlen(game->map[index]))
			return (0);
		index++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!is_rectangular(game))
		return (ft_putstr_fd_0("The map isn't rectangular\n", 2));
	if (!is_surrounded_by_walls(game))
		return (ft_putstr_fd_0("The map isn't surrounded by walls.\n", 2));
	if (!check_els(game))
		return (ft_putstr_fd_0("The map doesn't have valid elements.\n", 2));
	if (game->collectible == 0)
		return (0);
	return (1);
}
