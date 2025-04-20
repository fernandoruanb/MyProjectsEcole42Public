/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:31:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 21:09:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>

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
	int		player_x;
	int		player_y;
	char	**maps;
}	t_game;

int		check_cub(const char *filename);
int		free_game(t_game *game);
int		init_game(const char *filename, t_game *game);
char	**get_map(const char *filename);
int		free_game(t_game *game);
void	show_map(t_game *game);
void	init_all_things(t_game *game);
int	get_map_textures(t_game *game);
int	get_no_texture(t_game *game);
int	get_so_texture(t_game *game);
int	get_we_texture(t_game *game);
int	get_ea_texture(t_game *game);
int	get_floor_colours(t_game *game);
int	get_ceiling_colours(t_game *game);
int	get_true_map(t_game *game);
void	show_textures(t_game *game);
int	is_anything_null(t_game *game);
int	is_valid_map(t_game *game);
int	check_colours(t_game *game);
int	check_true_map(t_game *game);

#endif /* CUB3D_H */
