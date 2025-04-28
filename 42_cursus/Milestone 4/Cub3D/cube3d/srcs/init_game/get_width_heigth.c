/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_heigth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:10:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 19:48:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_width(t_game *game)
{
	long	max;
	long	temp;
	long	index;

	max = 0;
	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		temp = 0;
		while (game->true_game_map[index][temp] != '\0'
			&& game->true_game_map[index][temp] != '\n')
		{
			if (temp > INT_MAX)
				return (-1);
			temp++;
		}
		if (temp > max)
			max = temp;
		index++;
	}
	return (max);
}

static int	get_heigth(t_game *game)
{
	long	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		if (index > INT_MAX)
			return (-1);
		index++;
	}
	return (index);
}

int	get_width_heigth(t_game *game)
{
	game->width = get_width(game);
	if (game->width == -1)
		return (ft_putendl_fd_0("Error: invalid width", 2));
	game->width_map = game->width;
	game->width *= TILE_SIZE;
	game->heigth = get_heigth(game);
	if (game->heigth == -1)
		return (ft_putendl_fd_0("Error: invalid heigth", 2));
	game->heigth_map = game->heigth;
	game->heigth *= TILE_SIZE;
	return (1);
}
