# Name of the program

NAME = ft_display_file

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Archives .c

SRCS = ft_display_file.c

# Archives .o

OBJ = $(SRCS:.c=.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Clear archive .o

clean:
	rm -f $(OBJ)

# Clear all

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean all
