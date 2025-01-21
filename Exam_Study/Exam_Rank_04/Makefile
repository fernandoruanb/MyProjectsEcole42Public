# Name of the program or the library

NAME = microshell

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = srcs
INCDIR = includes

# SRCS

SRCS =  $(SRCDIR)/ft_strcmp.c\
	$(SRCDIR)/microshell.c

# OBJS

OBJS = $(SRCS:.c=.o)

# Main

all: $(NAME)

# Main rules

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

# clean

clean:
	rm -f $(OBJS)

# full clean

fclean: clean
	rm -f $(NAME)

# restart

re: fclean all

.PHONY: all fclean clean re
