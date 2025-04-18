#Name of the program or the library

NAME = cub3d

#Compilers and flags

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
MLXFLAGS = -L $(MLXDIR) -lmlx -lXext -lX11 -lm

#Directories

SRCDIR = .
INCDIR = .
MLXDIR = ../minilibx-linux
LIBFT_DIR = libft

# LIBFT

LIBFT = $(LIBFT_DIR)/libft.a

#SRCS

SRCS =  $(SRCDIR)/srcs/cub3d/main.c\
	$(SRCDIR)/srcs/validation/check_cub.c

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
