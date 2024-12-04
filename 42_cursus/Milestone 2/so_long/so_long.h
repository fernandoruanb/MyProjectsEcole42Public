/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:00:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/03 15:16:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif /* TILE_SIZE */

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*player_img;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_img;
	void	*floor_img;
}	t_game;

int		ft_putstr_fd(const char *s, int fd);
int		ft_putstr_fd_0(const char *s, int fd);
int		init_game(t_game *game, char *map_file);
size_t	ft_strlen(const char *s);

#endif /* SO_LONG_H */