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

int	get_so_texture(t_game *game)
{
	int		index;
	char	**get_so;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& game->maps[index][0] == 'S'
			&& game->maps[index][1] == 'O')
		{
			get_so = ft_split(game->maps[index], ' ');
			game->so_texture = ft_strdup(get_so[1]);
			if (!game->so_texture)
			{
				free_splits(NULL, get_so, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_so, NULL, NULL);
		}
		index++;
	}
	return (1);
}
