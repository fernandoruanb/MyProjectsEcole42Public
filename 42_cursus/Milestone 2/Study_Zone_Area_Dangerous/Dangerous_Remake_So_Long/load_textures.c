/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:09:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 13:40:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_more_images(t_game *game)
{
	int	width;
	int	height;

	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit_img", &width, &height);
	if (!game->exit_img)
		return (ft_putstr_fd_0("Error loading exit_img.\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error TILE_SIZE exit_img\n", 2));
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor_img", &width, &height);
	if (!game->floor_img)
		return (ft_putstr_fd_0("Error loading floor_img.\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error TILE_SIZE floor_img.\n", 2));
	return (1);
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player_img", &width, &height);
	if (!game->player_img)
		return (ft_putstr_fd_0("Error player_img loading.\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error TILE_SIZE player.\n", 2));
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/collectible_img", &width, &height);
	if (!game->collectible_img)
		return (ft_putstr_fd_0("Error collectible_img load\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error TILE_SIZE collectible.\n", 2));
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall_img", &width, &height);
	if (!game->wall_img)
		return (ft_putstr_fd_0("Error loading wall_img.\n", 2));
	if (width != TILE_SIZE || height != TILE_SIZE)
		return (ft_putstr_fd_0("Error TILE_SIZE wall_img.\n", 2));
	if (!load_more_images(game))
		return (0);
	return (1);
}
