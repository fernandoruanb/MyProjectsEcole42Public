#Name of the program or library

NAME = so_long

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  $(SRCDIR)/ft_putstr_fd.c

# OBJS

OBJS = $(SRCS:$(SRCDIR)%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $?

# clear

clear:
	rm -f $(OBJS)

# Full clear

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean all

.PHONY: all fclean clear re 
	
