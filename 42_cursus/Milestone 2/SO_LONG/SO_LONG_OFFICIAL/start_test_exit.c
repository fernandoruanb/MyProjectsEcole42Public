/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_test_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:50:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 18:09:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_test_exit(char **map_copy, int x, int y, t_game *game)
{
	if (x >= game->lines || y >= game->length || x < 0
		|| y < 0)
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'V')
		return ;
	if (map_copy[x][y] == 'E')
	{
		game->exit_t++;
		map_copy[x][y] = 'V';
	}
	if (map_copy[x][y] == 'C')
		map_copy[x][y] = 'V';
	if (map_copy[x][y] == '0')
		map_copy[x][y] = 'V';
	start_test_exit(map_copy, x + 1, y, game);
	start_test_exit(map_copy, x - 1, y, game);
	start_test_exit(map_copy, x, y + 1, game);
	start_test_exit(map_copy, x, y - 1, game);
}

