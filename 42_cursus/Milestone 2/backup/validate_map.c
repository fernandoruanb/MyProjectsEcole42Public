/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:44:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 18:58:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strchr_v3(const char *s, int c)
{
	size_t	length;
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	length = 0;
	while (s[length] != '\0')
		length++;
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}

static int	check_elements(char **map, t_game *game)
{
	char	*set;
	int		index;
	int		s_index;

	set = "01PCE";
	index = 0;
	while (map[index] != NULL)
	{
		s_index = 0;
		while (map[index][s_index] != '\0')
		{
			if (!ft_strchr_v3(set, map[index][s_index]))
				return (0);
			if (map[index][s_index] == 'C')
				game->collectible++;
			if (map[index][s_index] == 'P')
			{
				game->player_x = index;
				game->player_y = s_index;
			}
			s_index++;
		}
		index++;
	}
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	size_t	index;
	size_t	length;
	size_t	letter;

	index = 0;
	length = ft_strlen(map[index]);
	while (map[index] != NULL)
	{
		letter = 0;
		if (index == 0 || map[index + 1] == NULL)
		{
			while (map[index][letter] != '\0')
			{
				if (map[index][letter] != '1')
					return (0);
				letter++;
			}
		}
		else if (map[index][0] != '1' || map[index][length - 1] != '1')
			return (0);
		index++;
	}
	return (1);
}

static int	is_rectangular(char **map)
{
	size_t	length;
	size_t	lines;
	size_t	index;

	length = ft_strlen(map[0]);
	lines = 0;
	while (map[lines] != NULL)
		lines++;
	index = 0;
	while (index < lines)
	{
		if (length != ft_strlen(map[index]))
			return (0);
		index++;
	}
	return (1);
}

int	validate_map(char **map, t_game *game)
{
	if (!is_rectangular(map))
		return (ft_putstr_fd_0("The map is not rectangular.\n", 2));
	if (!is_surrounded_by_walls(map))
		return (ft_putstr_fd_0("The map isn't surrounded by walls.\n", 2));
	if (!check_elements(map, game))
		return (ft_putstr_fd_0("There is/are invalid elements on map.\n", 2));
	return (1);
}
