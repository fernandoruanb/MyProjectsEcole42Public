/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_true_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:39:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 21:06:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_special_chars(t_game *game)
{
	int	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		if (game->true_game_map[index]
			&& (game->true_game_map[index][0] == '\n'
			|| game->true_game_map[index][0] == '\t'
			|| game->true_game_map[index][0] == '\v'
			|| game->true_game_map[index][0] == '\f'
			|| game->true_game_map[index][0] == '\r'
			|| game->true_game_map[index][0] == '\b'
			|| game->true_game_map[index][0] == '\a'
			|| game->true_game_map[index][0] == '\\'))
			return (0);
		index++;
	}
	return (1);
}

int	check_true_map(t_game *game)
{
	if (!check_special_chars(game))
		return (ft_putendl_fd_0("Newlines or Tabs found on map", 2));
	return (1);
}
