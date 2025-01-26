#Name of the program or library

NAME = so_long

# Compilers and flags

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra 
MLXFLAGS = -L $(MLXDIR) -lmlx -lXext -lX11 -lm

# Directories

SRCDIR = .
INCDIR = .
MLXDIR = /usr/local/lib

# SRCS

SRCS =  $(SRCDIR)/main.c\
	$(SRCDIR)/ft_putstr_fd_1.c\
	$(SRCDIR)/ft_putstr_fd_0.c\
	$(SRCDIR)/init_game.c\
	$(SRCDIR)/ft_strlen.c\
	$(SRCDIR)/get_next_line.c\
	$(SRCDIR)/ft_printf.c\
	$(SRCDIR)/parse_format.c\
	$(SRCDIR)/handle_specifier.c\
	$(SRCDIR)/print_char.c\
	$(SRCDIR)/print_str.c\
	$(SRCDIR)/convert_int_to_str.c\
	$(SRCDIR)/convert_hex_to_str.c\
	$(SRCDIR)/convert_unsigned_to_str.c\
	$(SRCDIR)/convert_ptr_to_str.c\
	$(SRCDIR)/print_percentage.c\
	$(SRCDIR)/ft_putstr_fd_n.c\
	$(SRCDIR)/ft_calloc.c\
	$(SRCDIR)/read_map.c\
	$(SRCDIR)/validate_map.c\
	$(SRCDIR)/render_map.c\
	$(SRCDIR)/load_textures.c\
	$(SRCDIR)/free_game.c\
	$(SRCDIR)/key_press.c\
	$(SRCDIR)/get_next_line_utils.c\
	$(SRCDIR)/ft_strchr_v3.c\
	$(SRCDIR)/load_image.c\
	$(SRCDIR)/initialize_heap_variables.c\
	$(SRCDIR)/check_ber.c\
	$(SRCDIR)/flood_fill.c

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(MLXDIR) -o $(NAME) $(OBJS) $(MLXFLAGS)

# clear

clean:
	rm -f $(OBJS)

# Full clear

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean all

.PHONY: all fclean clean re	
