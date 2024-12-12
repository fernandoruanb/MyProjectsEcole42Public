# Name of the program or library

NAME = push_swap

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  $(SRCDIR)/main.c\
	$(SRCDIR)/parse_args.c\
	$(SRCDIR)/ft_putstr_fd_1.c\
	$(SRCDIR)/ft_putstr_fd_0.c

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main 

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

# Clear

clean:
	rm -f $(OBJS)

# Full clear

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean all

.PHONY: all fclean clean re
