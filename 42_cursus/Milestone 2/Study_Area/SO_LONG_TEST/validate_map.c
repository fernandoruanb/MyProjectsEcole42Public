/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:56:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/11 15:25:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_each_thing(char el, t_game *game)
{
	char	*set;

	set = "PCE01\n";
	if (el == 'E')
		game->exits++;
	if (el == 'E' && game->exits > 1)
		return (ft_putstr_fd_0("Too many exits.\n", 2));
	if (el == 'P')
		game->players++;
	if (el == 'P' && game->players > 1)
		return (ft_putstr_fd_0("Too many players.\n", 2));
	if (el == 'C')
		game->collectibles++;
	if (!ft_strchr_v3(set, el))
		return (ft_putstr_fd_0("Invalid element.\n"), 2);
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
			if (!check_each_thing(game->map[index][s_index], game))
				return (0);
			s_index++;
		}
		index++;
	}
	if (game->collectibles == 0)
		return (ft_putstr_fd_0("Too few collectibles.\n", 2));
	if (game->players == 0)
		return (ft_putstr_fd_0("Too few players.\n", 2));
	if (game->exits == 0)
		return (ft_putstr_fd_0("Too few exits.\n", 2));
	return (1);
}

static int	is_surrounded_by_walls(t_game *game)
{
	int	index;
	int	length;
	int	s_index;

	index = 0;
	length = ft_strlen(game->map[0]);
	while (game->map[index] != NULL)
	{
		if (index == 0 || game->map[index + 1] == NULL)
		{
			s_index = 0;
			while (game->map[index][s_index] != '\0' &&
				game->map[index][s_index] != '\n')
			{
				if (game->map[index][s_index] != '1')
					return (0);
				s_index++;
			}
		}
		else if (game->map[index][0] != '1'
			|| game->map[index][length - 2] != '1')
			return (0);
		index++;
	}
	return (1);
}

static int	is_rectangular(t_game *game)
{
	int	length;
	int	index;

	length = ft_strlen(game->map[0]) - 1;
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
		return (ft_putstr_fd_0("Map isn't rectangular.\n", 2));
	if (!is_surrounded_by_walls(game))
		return (ft_putstr_fd_0("Map isn't surrounded by walls.\n", 2));
	if (!check_els(game))
		return (ft_putstr_fd_0(game));
	return (1);
}
