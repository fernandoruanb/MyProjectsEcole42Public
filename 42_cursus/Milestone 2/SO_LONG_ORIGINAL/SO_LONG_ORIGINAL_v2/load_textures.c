/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:28:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/13 11:17:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	if (!load_image((void **)&game->player_img, "textures/ender64.xpm", game))
		return (ft_putstr_fd_0("Error loading texture.\n", 2));
	game->player_flag = 1;
	if (!load_image((void **)&game->collectible_img,
			"textures/Emerald_divine64.xpm", game))
		return (ft_putstr_fd_0("Error loading texture.\n", 2));
	game->collectible_flag = 1;
	if (!load_image((void **)&game->exit_img, "textures/exit64.xpm", game))
		return (ft_putstr_fd_0("Error loading texture.\n", 2));
	game->exit_flag = 1;
	if (!load_image((void **)&game->floor_img, "textures/floor64.xpm", game))
		return (ft_putstr_fd_0("Error loading texture.\n", 2));
	game->floor_flag = 1;
	if (!load_image((void **)&game->wall_img, "textures/wall64.xpm", game))
		return (ft_putstr_fd_0("Error loading texture.\n", 2));
	game->wall_flag = 1;
	return (1);
}
