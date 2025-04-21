/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:49:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/20 19:07:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_each_element(char c, t_game *game, int x, int y)
{
	char	*elements;

	elements = "01NSEW";
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		game->players++;
		if (game->players > 1)
			return (ft_putendl_fd_0("Too many players", 2));
		game->player_x = x;
		game->player_y = y;
	}
	if (!ft_strchr(elements, c) && c != ' ')
		return (ft_putendl_fd_0("Invalid element on map", 2));
	return (1);
}

int	check_elements(t_game *game)
{
	int		index;
	int		count;
	char	c;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count]
			&& (game->true_game_map[index][count] == ' '
			|| game->true_game_map[index][count] == '\t'))
			count++;
		while (game->true_game_map[index][count] != '\n'
			&& game->true_game_map[index][count] != '\0')
		{
			c = game->true_game_map[index][count];
			if (!check_each_element(c, game, index, count))
				return (0);
			count++;
		}
		index++;
	}
	if (game->players != 1)
		return (ft_putendl_fd_0("The map doesn't have a player", 2));
	return (1);
}
