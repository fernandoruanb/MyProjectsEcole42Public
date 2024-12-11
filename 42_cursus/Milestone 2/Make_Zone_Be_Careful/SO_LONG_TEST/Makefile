# Name of the program or the library

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
	$(SRCDIR)/init_game.c\
	$(SRCDIR)/read_map.c\
	$(SRCDIR)/validate_map.c\
	$(SRCDIR)/ft_strlen.c\
	$(SRCDIR)/render_map.c

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

# full clear

fclean: clean
	rm -f $(NAME)

# restart

re: fclean all

.PHONY: all fclean clean re
