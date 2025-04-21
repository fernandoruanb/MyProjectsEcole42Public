/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 19:10:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_no_texture(t_game *game)
{
	int		index;
	char	**get_no;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (game->maps[index][0] && game->maps[index][1]
			&& game->maps[index][0] == 'N'
			&& game->maps[index][1] == 'O')
		{
			get_no = ft_split(game->maps[index], ' ');
			if (!check_split_length(get_no))
				return (free_dynamic_texture(get_no));
			game->no_texture = ft_strdup(get_no[1]);
			if (!game->no_texture)
			{
				free_splits(NULL, get_no, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_no, NULL, NULL);
		}
		index++;
	}
	return (1);
}
