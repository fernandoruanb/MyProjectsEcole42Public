/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/05 15:43:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *filename)
{
	char	**map;
	int		file_descriptor;
	int		lines;
	int		index;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("There was a mistake opening file\n", 2));
	lines = 0;
	while ((get_next_line(file_descriptor)) != NULL)
		lines++;
	close(file_descriptor);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (ft_putstr_fd_n("There was a mistake reopen file.\n", 2));
	map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (ft_putstr_fd_n("Error allocating memory to map.\n", 2));
	index = 0;
	while (index < lines)
		map[index++] = get_next_line(file_descriptor);
	map[lines] = NULL;
	close(file_descriptor);
	return (map);
}
