/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cosplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:55:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 12:00:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_collectible(t_game *game)
{
	if (game->collectible == 0)
		return (0);
	return (1);
}

int	check_cosplay(char **map, t_game *game)
{
	int	index;
	int	s_index;

	index = 0;
	s_index = 0;
	while (map[index] != NULL)
	{
		s_index = 0;
		while (map[index][s_index] != '\0')
		{
			if (map[index][s_index] == 'P')
				game->player++;
			if (game->player > 1)
				return (0);
			s_index++;
		}
		index++;
	}
	if (game->player == 0 || !(check_collectible(game)))
		return (0);
	return (1);
}
