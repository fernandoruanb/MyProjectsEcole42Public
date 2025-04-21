/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:55:55 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/21 19:20:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_colours;
	char	*ceiling_colours;
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

#endif
