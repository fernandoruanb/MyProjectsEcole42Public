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

int	get_ea_texture(t_game *game)
{
	int		index;
	char	**get_ea;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& game->maps[index][0] == 'E'
			&& game->maps[index][1] == 'A')
		{
			get_ea = ft_split(game->maps[index], ' ');
			game->ea_texture = ft_strdup(get_ea[1]);
			if (!game->ea_texture)
			{
				free_splits(NULL, get_ea, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_ea, NULL, NULL);
		}
		index++;
	}
	return (1);
}
