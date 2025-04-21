#Name of the program or the library

NAME = cub3d

#Compilers and flags

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
MLXFLAGS = -L $(MLXDIR) -lmlx -lXext -lX11 -lm

#Directories

SRCDIR = srcs
INCDIR = includes
MLXDIR = minilibx-linux
LIBFT_DIR = libft

# LIBFT

LIBFT = $(LIBFT_DIR)/libft.a

#SRCS

SRCS =  $(SRCDIR)/cub3d/main.c\
	$(SRCDIR)/validation/check_cub.c\
	$(SRCDIR)/init_game/init_game.c\
	$(SRCDIR)/init_game/get_map.c\
	$(SRCDIR)/free_game/free_game.c\
	$(SRCDIR)/init_game/init_all_things.c\
	$(SRCDIR)/init_game/get_map_textures.c\
	$(SRCDIR)/utils/show_map.c\
	$(SRCDIR)/init_game/get_no_texture.c\
	$(SRCDIR)/init_game/get_so_texture.c\
	$(SRCDIR)/init_game/get_we_texture.c\
	$(SRCDIR)/init_game/get_ea_texture.c\
	$(SRCDIR)/init_game/get_floor_colours.c\
	$(SRCDIR)/init_game/get_ceiling_colours.c\
	$(SRCDIR)/init_game/get_true_map.c\
	$(SRCDIR)/utils/show_textures.c\
	$(SRCDIR)/validation/is_valid_map.c\
	$(SRCDIR)/validation/is_anything_null.c\
	$(SRCDIR)/validation/check_colours.c\
	$(SRCDIR)/validation/check_true_map.c\
	$(SRCDIR)/validation/check_is_valid_png.c\
	$(SRCDIR)/validation/check_elements.c\
	$(SRCDIR)/validation/get_all_lines.c\
	$(SRCDIR)/validation/check_entire_wall.c\
	$(SRCDIR)/validation/check_first_last_wall.c\
	$(SRCDIR)/validation/check_invalid_access.c\
	$(SRCDIR)/validation/flood_fill.c

#OBJS

OBJS =  $(SRCS:.c=.o)

#Main

all: $(NAME)

#All the magic happens here

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(MLXDIR) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)

# .c -> .o

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

#fclean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

#restart

re: fclean all

.PHONY: all fclean clean re
