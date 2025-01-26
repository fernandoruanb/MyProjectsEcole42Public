/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:55:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 17:55:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(t_game *game)
{
	int		index;
	char	**map_copy;

	map_copy = (char **)malloc((game->lines + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	index = 0;
	while (index < game->lines)
	{
		map_copy[index] = ft_strdup(game->map[index]);
		if (!map_copy[index])
		{
			index--;
			while (index >= 0)
				free(map_copy[index--]);
			free(map_copy);
			return (NULL);
		}
		index++;
	}
	map_copy[index] = NULL;
	return (map_copy);
}

