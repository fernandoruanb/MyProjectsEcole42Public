/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_NO_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 09:45:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_floor_colours(t_game *game)
{
	int		index;
	char	**get_f_colours;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& game->maps[index][0] == 'F')
		{
			get_f_colours = ft_split(game->maps[index], ' ');
			game->floor_colours = ft_strdup(get_f_colours[1]);
			if (!game->floor_colours)
			{
				free_splits(NULL, get_f_colours, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_f_colours, NULL, NULL);
		}
		index++;
	}
	return (1);
}
