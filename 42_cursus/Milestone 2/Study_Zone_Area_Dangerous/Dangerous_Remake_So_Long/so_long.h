/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:37:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 13:19:27 by fruan-ba         ###   ########.fr       */
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
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		collectible;
	int		player;
	int		move;
	int		width;
	int		height;
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
int		render_map(t_game *game);
int		keypress(int keycode, t_game *game);
int		load_textures(t_game *game);
int		render_map(t_game *game);
int		free_game(t_game *game);
int		ft_putstr_fd_0(const char *s, int fd);
int		ft_putstr_fd_1(const char *s, int fd);
char	**ft_putstr_fd_n(const char *s, int fd);
int	convert_int_to_str(va_list args);
int	convert_hex_to_str(char specifier, va_list args);
int	convert_ptr_to_str(va_list args);
int	convert_unsigned_to_str(va_list args);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_percentage(va_list args);
int	ft_printf(const char *format, ...);
int	parse_format(const char *format, va_list args);
int	handle_specifier(char specifier, va_list args);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_strlen(const char *s);

#endif /* TILE_SIZE */
