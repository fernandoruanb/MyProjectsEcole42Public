# Name of the program or library

NAME = ircserver

# Compilers and flags

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  internet.cpp\
	utils/atoiIRC.cpp

#OBJS

OBJS = $(SRCS:.cpp=.o)

# Main

all: $(NAME)

# All the magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

# .cpp -> .o

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#clean

clean:
	rm -f $(OBJS)

#full clean

fclean: clean
	rm -f $(NAME)

#restart

re: fclean all

.PHONY: all fclean clean re
