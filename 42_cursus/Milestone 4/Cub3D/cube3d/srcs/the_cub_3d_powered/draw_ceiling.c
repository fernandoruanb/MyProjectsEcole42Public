/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:17:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 19:25:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_game *game, int x)
{
	int	colour;
	int	y;

	y = 0;
	colour = ft_atoi_base(game->rrggbb_ceiling + 2, 16);
	if (game->draw_3d_center_s < 0)
		game->draw_3d_center_s = 0;
	while (y < game->draw_3d_center_s)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			400 + x, 400 + y, colour);
		y++;
	}
}
