/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:26:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/18 20:26:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		free(game->maps[index]);
		index++;
	}
	free(game->maps);
}

int	free_game(t_game *game)
{
	if (!game)
		return (0);
	if (game->maps)
		free_map(game);
	return (1);
}
