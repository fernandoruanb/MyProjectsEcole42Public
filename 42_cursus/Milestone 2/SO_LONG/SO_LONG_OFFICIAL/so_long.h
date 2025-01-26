/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:00:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 16:45:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif /* TILE_SIZE */

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectible;
	int		player;
	int		exit;
	int		lines;
	int		length;
	int		moves;
	void	*player_img;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_img;
	void	*floor_img;
	int		x;
	int		y;
	int		exit_t;
	int		collectibles;
	int		mlx_flag;
	int		win_flag;
	int		floor_flag;
	int		wall_flag;
	int		player_flag;
	int		collectible_flag;
	int		exit_flag;
}	t_game;

int		ft_putstr_fd_1(const char *s, int fd);
int		ft_putstr_fd_0(const char *s, int fd);
int		init_game(t_game *game, char *map_file);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
int		parse_format(const char *format, va_list args);
int		handle_specifier(va_list args, char specifier);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_percentage(void);
int		convert_int_to_str(va_list args);
int		convert_hex_to_str(va_list args, char specifier);
int		convert_ptr_to_str(va_list args);
int		convert_unsigned_to_str(va_list args);
char	**ft_putstr_fd_n(const char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	**read_map(char *filename, t_game *game);
int		validate_map(char **map, t_game *game);
int		render_map(t_game *game);
int		load_textures(t_game *game);
int		free_game(t_game *game);
int		key_press(int keycode, t_game *game);
char	*ft_strchr_v3(const char *s, int c);
int		load_image(void **img, char *path, t_game *game);
void	initialize_heap_variables(t_game *game);
int		check_ber(const char *filename);
int		flood_fill(t_game *game);

#endif /* SO_LONG_H */
