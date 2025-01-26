/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:10:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 16:53:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **map_copy)
{
	int	index;

	index = 0;
	while (map_copy[index])
	{
		free(map_copy[index]);
		index++;
	}
	free(map_copy);
}

static void	start_test(char **map_copy, int x, int y, t_game *game)
{
	if (x > game->lines || y >= game->length || x < 0
		|| y < 0)
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'V')
		return ;
	if (map_copy[x][y] == 'C' || map_copy[x][y] == 'E')
	{
		if (map_copy[x][y] == 'C')
			game->collectibles--;
		else
			game->exit_t++;
		map_copy[x][y] = 'V';
	}
	if (map_copy[x][y] == '0')
		map_copy[x][y] = 'V';
	start_test(map_copy, x + 1, y, game);
	start_test(map_copy, x - 1, y, game);
	start_test(map_copy, x, y + 1, game);
	start_test(map_copy, x, y - 1, game);
}

static char	*ft_strdup(const char	*s)
{
	size_t	index;
	size_t	length;
	char	*buffer;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		buffer[index] = s[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

static char	**get_map(t_game *game)
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

int	flood_fill(t_game *game)
{
	char	**map_copy;

	game->length = 0;
	while (game->map[0][game->length] != '\n'
		&& game->map[0][game->length] != '\0')
		game->length++;
	game->lines = 0;
	while (game->map[game->lines])
		game->lines++;
	map_copy = get_map(game);
	if (map_copy == NULL)
		return (0);
	game->x = game->player_x;
	game->y = game->player_y;
	game->collectibles = game->collectible;
	game->exit_t = 0;
	start_test(map_copy, game->x, game->y, game);
	if (game->collectibles != 0 || game->exit_t != 1)
	{
		free_map_copy(map_copy);
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}
