#Name of the program of the library

NAME = philo

# Compilers and flags

CC = cc
CFLAGS = -g3 -pthread -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = includes

# SRCS

SRCS = $(shell find . -type f -name "*.c")

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# .c -> .o

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

# Clean

clean:
	rm -f $(OBJS)

# Full clean

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean $(NAME)

.PHONY: NAME all clean fclean re
