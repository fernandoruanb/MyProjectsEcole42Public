/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_we_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 10:59:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_we_texture(t_game *game)
{
	int		index;
	char	**get_we;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& game->maps[index][0] == 'W'
			&& game->maps[index][1] == 'E')
		{
			get_we = ft_split(game->maps[index], ' ');
			remove_spaces_and_tabs(&get_we);
			if (!check_split_length(get_we))
				return (free_dynamic_texture(get_we));
			game->we_texture = ft_strdup(get_we[1]);
			if (!game->we_texture)
			{
				free_splits(NULL, get_we, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_we, NULL, NULL);
		}
		index++;
	}
	return (1);
}
