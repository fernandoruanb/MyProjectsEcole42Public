/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:21:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/20 18:33:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_invalid_access(t_game *game)
{
	int	lines;
	int	index;
	int	count;

	lines = get_all_lines(game);
	index = 1;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count] != '\n' &&
			game->true_game_map[index][count] != '\0')
		{
			if (game->true_game_map[index][count] == '0'
				&& game->true_game_map[index - 1][count] == ' ')
				return (ft_putendl_fd_0("Invalid access", 2));
			count++;
		}
		index++;
	}
	return (1);
}
