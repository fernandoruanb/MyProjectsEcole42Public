#Name of the program or library

NAME = so_long

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  $(SRCDIR)/main.c\
	$(SRCDIR)/ft_putstr_fd.c\
	$(SRCDIR)/ft_putstr_fd_0.c\
	$(SRCDIR)/init.game.c\
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
	$(SRCDIR)/validate_map.c

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

# clear

clean:
	rm -f $(OBJS)

# Full clear

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean all

.PHONY: all fclean clear re 	
