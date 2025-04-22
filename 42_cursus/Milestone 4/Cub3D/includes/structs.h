/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:55:55 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/22 17:26:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <limits.h>
# include "cub3d.h"
# define TILE_SIZE 64

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
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
	char	**maps;
	int		no_texture_index;
	int		so_texture_index;
	int		we_texture_index;
	int		ea_texture_index;
	int		floor_colours_index;
	int		ceiling_colours_index;
}	t_game;

int	free_dynamic_texture(char **split);
int	rgb_to_rrggbb(t_game *game);
#endif
