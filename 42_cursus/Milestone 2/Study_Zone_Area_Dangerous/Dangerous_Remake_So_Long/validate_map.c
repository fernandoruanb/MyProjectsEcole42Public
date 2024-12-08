/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:12:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 14:18:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strchr_v3(const char *s, int c)
{
	int	index;
	int	length;

	index = 0;
	length = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[length]);
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}

static int	check_els(char **map, t_game *game)
{
	static int	count_p;
	static int	count_e;
	char		*set;
	char		*test_map;

	if (!count_p)
		count_p = 0;
	if (!count_e)
		count_e = 0;
	set = "0PEC1";
	while (map[index] != NULL)
	{
		s_index = 0;
		test_map = ft_strtrim(map[index], '\n');
		if (!test_map)
			return (ft_putstr_fd_0("Error trim map.\n", 2));
		while (test_map[s_index] != '\0')
			if (!ft_strchr_v3(set, test_map[s_index++]))
				return (0);
		free(test_map);
		index++;
	}
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	int	index;
	int	s_index;

	index = 0;
	while (map[index] != NULL)
	{
		s_index = 0;
		if (index == 0 || map[index + 1] == NULL)
		{
			while (map[index][s_index] != '\n'
				&& map[index][s_index] != '\0')
			{
				if (map[index][s_index] != '1')
					return (0);
				s_index++;
			}
		}
		else if (map[index][0] != '1' || map[index][length - 2] != '1')
			return (0);
		index++;
	}
	return (1);
}

static int	is_rectangular(char **map)
{
	int	index;
	int	length;

	length = ft_strlen(map[0]);
	index = 0;
	while (map[index] != NULL)
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
		return (ft_putstr_fd_0("The map isn't rectangular.\n", 2));
	if (!is_surrounded_by_walls(map))
		return (ft_putstr_fd_0("The map isn't surrounded by walls.\n", 2));
	if (!check_els(map))
		return (ft_putstr_fd_0("There is/are invalid els on the map.\n", 2));
	if (!check_cosplay(map))
		return (ft_putstr_fd_0("There isn't a player or collectibles.\n", 2));
	return (1);
}
