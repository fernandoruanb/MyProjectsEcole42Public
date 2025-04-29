/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:55:55 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/29 11:51:05 by jonas            ###   ########.fr       */
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

typedef struct s_game	t_game;

typedef struct s_keys
{
	int	key;
	void	(*f)(t_game*);
}	t_keys;

typedef struct s_game
{
	t_mlx	mlx;
	t_map	map;
	t_keys	keys;
	char	*no_texture;
	void	*no_addr;
	void	*so_addr;
	void	*ea_addr;
	void	*we_addr;
	int		bpp_no;
	int		bpp_so;
	int		bpp_we;
	int		bpp_ea;
	int		line_length_no;
	int		line_length_so;
	int		line_length_we;
	int		line_length_ea;
	int		endian_no;
	int		endian_so;
	int		endian_we;
	int		endian_ea;
	double	plane_x;
	double	plane_y;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_colours;
	char	*rrggbb_floor;
	char	*ceiling_colours;
	char	*rrggbb_ceiling;
	int		width;
	int		heigth;
	int		screen_w;
	int		screen_h;
	char	**true_game_map;
	int		players;
	int		invalid_map;
	int		player_x;
	int		player_y;
	int		offset_x;
	int		offset_y;
	double	dir_x;
	double	dir_y;
	int		min_col;
	int		min_row;
	int		max_col;
	double	distance;
	double	distance_r;
	double	distance_l;
	int		wall_3d_height;
	int		wall_3d_width;
	int		center_win;
	int		draw_3d_center_s;
	int		draw_3d_center_e;
	double	px_start;
	double	py_start;
	double	angle;
	double	angle_left;
	double	angle_right;
	double	dir_get_x;
	double	dir_get_y;
	double	dir_left_x;
	double	dir_left_y;
	double	dir_right_x;
	double	dir_right_y;
	double	dir_x_c;
	double	dir_y_c;
	double	distance_x;
	double	angle_k;
	double	target_x;
	void	*ea_img;
	void	*we_img;
	void	*no_img;
	void	*so_img;
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
	char	player_eye;
}	t_game;

int			free_dynamic_texture(char **split);
int			rgb_to_rrggbb(t_game *game);
void		minimap(t_game *game);
void		draw_fov(t_game *game);

#endif
