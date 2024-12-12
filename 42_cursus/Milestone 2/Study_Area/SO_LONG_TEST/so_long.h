/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:48:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/11 16:00:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif /* TILE_SIZE */

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		moves;
	int		width;
	int		height;
	int		exits;
	int		collectibles;
	int		players;
	int		player_x;
	int		player_y;
	void	*wall_img;
	void	*exit_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
}	t_game;

int		init_game(char *filename, t_game *game);
char	**read_map(char *filename);
int		validate_map(t_game *game);
int		ft_strlen(const char *s);
int		render_map(t_game *game);

#endif /* SO_LONG_H */
