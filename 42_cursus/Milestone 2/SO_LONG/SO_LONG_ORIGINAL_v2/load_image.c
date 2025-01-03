/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:55:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 11:12:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_image(void **img, char *path, t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = NULL;
	*img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!*img)
	{
		ft_printf("Error path: %s\n", path);
		return (ft_putstr_fd_0("Error in load image\n", 2));
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		ft_printf("Error path: %s\n", path);
		mlx_destroy_image(game->mlx_ptr, *img);
		return (ft_putstr_fd_0("Wrong image destroyed.\n", 2));
	}
	return (1);
}
