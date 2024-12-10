/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:18:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 18:03:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif /* TILE_SIZE */

# include <stdarg.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;
	void	*collectible_img;
	int		player_x;
	int		player_y;
	int		moves;
	int		players;
	int		exits;
	int		collectible;
	int		width;
	int		height;
}	t_game;

int	read_map(char *filename, t_game *game);
int	init_game(char *filename, t_game *game);
int	validate_game(t_game *game);
int	free_game(t_game *game);

#endif /* SO_LONG_H */
