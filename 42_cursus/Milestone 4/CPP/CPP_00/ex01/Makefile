#Name of the program or the library

NAME = phonebook

#Cppflags

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = phonebook.hpp

#SRCS

SRCS = phonebook.cpp

#OBJS

OBJS = $(SRCDIR/%.c=%.o)

#Main

all: $(NAME)

# .c > .o

$NAME: $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#clean

clean:
	rm -rf $(OBJS)

#fclean

fclean: clean
	rm -rf $(NAME)

#restart

re: all fclean

.PHONY: all fclean clean re
