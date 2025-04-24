/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:31:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 17:23:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include "validation.h"
# include "window.h"
# include "ray_cast.h"

# define COLOUR_FLOOR 0xff0000
# define COLOUR_WALL 0x00ff00
# define COLOUR_PLAYER 0x0000ff
# define COLOUR_DEFAULT 0x0000f6
# define MINIMAP_SCALE 0.125
# define ROTATION_SPEED 0.05

int		destroy(t_game *game);
int		get_width_heigth(t_game *game);
t_game	*get_t_game(void);
void	draw_radius(t_game *game);
void	update_angle_dir_x_y(t_game *game, int keycode);

#endif /* CUB3D_H */
