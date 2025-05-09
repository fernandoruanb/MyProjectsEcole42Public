/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_x_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:47:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/28 15:52:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_plane_x_y(t_game *game)
{
	game->plane_x = -game->dir_y * 0.66;
	game->plane_y = game->dir_x * 0.66;
}
