/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:37:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 19:19:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif /* TILE_SIZE */

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		collectible;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	void	*player_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
}	t_game;

int		init_game(char *filename, t_game *game);
int		ft_strlen(const char *s);
char	*ft_strchr_v3(const char *s, int c);
char	**read_map(char *filename, t_game *game);
int		validate_map(t_game *game);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		check_cosplay(int player);

#endif /* TILE_SIZE */
