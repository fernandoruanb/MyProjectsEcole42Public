/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_png.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:08:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 09:30:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_signature(char *file_path)
{
	unsigned char	signature[8];
	int				fd;
	ssize_t			bytes_read;

	ft_printf("%s\n", file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd_0("Inexistent file", 2));
	bytes_read = read(fd, signature, sizeof(signature));
	if (bytes_read == -1 || bytes_read < 8)
	{
		close(fd);
		return (ft_putendl_fd_0("Impossible PNG length", 2));
	}
	if (signature[0] == 0x89 && signature[1] == 0x50
		&& signature[2] == 0x4E && signature[3] == 0x47
		&& signature[4] == 0x0D && signature[5] == 0x0A
		&& signature[6] == 0x1A && signature[7] == 0x0A)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (ft_putendl_fd_0("Invalid signature PNG", 2));
}

static int	check_png(char *file_path)
{
	size_t	index;
	char	*check_str;
	char	*substr;
	size_t	length;

	check_str = ".png";
	index = 0;
	length = ft_strlen(file_path);
	while (file_path[index] != '\0')
	{
		if (file_path[index] == '.')
		{
			substr = ft_substr(file_path, index, length - index);
			if (ft_strcmp(substr, check_str) == 0)
			{
				free(substr);
				return (1);
			}
		}
		free(substr);
		index++;
	}
	return (ft_putendl_fd_0("File without .png file", 2));
}

int	check_is_valid_png(t_game *game)
{
	if (!check_signature(game->no_texture) || !check_png(game->no_texture))
		return (0);
	if (!check_signature(game->so_texture) || !check_png(game->so_texture))
		return (0);
	if (!check_signature(game->we_texture) || !check_png(game->we_texture))
		return (0);
	if (!check_signature(game->ea_texture) || !check_png(game->ea_texture))
		return (0);
	return (1);
}
