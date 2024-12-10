/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:21:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 18:49:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	other_images(t_game *game, int width, int height)
{
	game->collectible = mlx_xpm_to_image(game->mlx_ptr,
			"textures/Emerald_divine64.xpm", &width, &height);
	if (!game->collectible_img)
		return (ft_putstr_fd_0("Error collectible_img\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error collect wid/heig\n", 2));
	game->exit_img = mlx_xpm_to_image(game->mlx_ptr,
			"textures/exit64.xpm", &width, &height);
	if (!game->exit_img)
		return (ft_putstr_fd_0("Error exit_img load.\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error exit width/height\n", 2));
	return (1);
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->player_img = mlx_xpm_to_image(game->mlx_ptr,
			"textures/ender64.xpm", &width, &height);
	if (!game->player_img)
		return (ft_putstr_fd_0("Error player_img\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error player width/height", 2));
	game->floor_img = mlx_xpm_to_image(game->mlx_ptr,
			"textures/floor64.xpm", &width, &height);
	if (!game->floor_img)
		return (ft_putstr_fd_0("Error floor_img\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error floor width/height", 2));
	game->wall_img = mlx_xpm_to_image(game->mlx_ptr,
			"textures/wall64.xpm", &width, &height);
	if (!game->wall_img)
		return (ft_putstr_fd_0("Error wall_img.\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error wall width/height", 2));
	if (!other_images(game))
		return (0);
	return (1);
}
