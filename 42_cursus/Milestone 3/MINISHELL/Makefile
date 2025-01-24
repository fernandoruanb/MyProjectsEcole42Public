# Name of the program or the library

NAME = minishell

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = srcs
INCDIR = includes
LIBFT_DIR = libft

# LIBFT

LIBFT = libft/libft.a

# SRCS

SRCS =  $(SRCDIR)/minishell.c

# OBJS

OBJS = $(SRCS:%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFT_DIR) -o $(NAME) $(OBJS) $(LIBFT)

# clean

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

# full clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

# restart

re: fclean all

.PHONY: fclean all clean re
