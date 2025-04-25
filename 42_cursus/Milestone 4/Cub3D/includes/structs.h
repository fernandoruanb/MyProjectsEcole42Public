/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:55:55 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/24 17:27:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <limits.h>
# include "cub3d.h"
# define TILE_SIZE 64

typedef struct s_angle
{
	char	dir;
	int		angle;
}	t_angle;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_player
{
	int	x;
	int	y;
	int	angle;
}	t_player;

typedef struct s_map
{
	char		***map;
	t_player	player;
}	t_map;

typedef struct s_game
{
	t_mlx	mlx;
	t_map	map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_colours;
	char	*rrggbb_floor;
	char	*ceiling_colours;
	char	*rrggbb_ceiling;
	int		width;
	int		heigth;
	char	**true_game_map;
	int		players;
	int		invalid_map;
	int		player_x;
	int		player_y;
	int		offset_x;
	int		offset_y;
	double		dir_x;
	double		dir_y;
	int		min_col;
	int		min_row;
	int		max_col;
	double		angle;
	double		angle_left;
	double		angle_right;
	double		dir_left_x;
	double		dir_left_y;
	double		dir_right_x;
	double		dir_right_y;
	int		max_row;
	int		width_map;
	int		heigth_map;
	char	**maps;
	int		no_texture_index;
	int		so_texture_index;
	int		we_texture_index;
	int		ea_texture_index;
	int		floor_colours_index;
	int		ceiling_colours_index;
}	t_game;

int			free_dynamic_texture(char **split);
int			rgb_to_rrggbb(t_game *game);
void		minimap(t_game *game);
void		draw_fov(t_game *game);

#endif
