/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:28:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 14:39:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	main_imgs(t_game *game, int *width, int *heigth)
{
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/ender64.xpm", width, heigth);
	if (!game->player_img)
		return (ft_putstr_fd_0("Error loading player_img.\n", 2));
	game->player_flag = 1;
	if (*width != TILE_SIZE || *heigth != TILE_SIZE)
		return (ft_putstr_fd_0("Incorrect width and heigth 1.\n", 2));
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/Emerald_divine64.xpm", width, heigth);
	if (!game->collectible_img)
		return (ft_putstr_fd_0("Error loading collectible_img.\n", 2));
	game->collectible_flag = 1;
	if (*width != TILE_SIZE || *heigth != TILE_SIZE)
		return (ft_putstr_fd_0("Incorrect width and heigth 2.\n", 2));
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit64.xpm", width, heigth);
	if (!game->exit_img)
		return (ft_putstr_fd_0("Error loading exit_img.\n", 2));
	game->exit_flag = 1;
	if (*width != TILE_SIZE || *heigth != TILE_SIZE)
		return (ft_putstr_fd_0("Incorrect width and heigth 4.\n", 2));
	return (1);
}

int	load_textures(t_game *game)
{
	int	width;
	int	heigth;

	width = 0;
	heigth = 0;
	if (!main_imgs(game, &width, &heigth))
		return (ft_putstr_fd_0("Error loading main_imgs.\n", 2));
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor64.xpm", &width, &heigth);
	if (!game->floor_img)
		return (ft_putstr_fd_0("Error loading the last img.\n", 2));
	game->floor_flag = 1;
	if (width != TILE_SIZE || heigth != TILE_SIZE)
		return (ft_putstr_fd_0("Incorrect width or heigth 5.\n", 2));
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall64.xpm", &width, &heigth);
	if (!game->wall_img)
		return (ft_putstr_fd_0("Error loading wall_img.\n", 2));
	game->wall_flag = 1;
	if (width != TILE_SIZE || heigth != TILE_SIZE)
		return (ft_putstr_fd_0("Incorrect width and heigth 3.\n", 2));
	return (1);
}
