#Name of the program or the library

NAME = serialize

#Compilers and flags

CC = c++
CFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  $(SRCDIR)/Serializer.cpp\
	$(SRCDIR)/main.cpp

#OBJS

OBJS = $(SRCS:.cpp=.o)

#main

all: $(NAME)

#All the magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#.cpp -> .o

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#clean

clean:
	rm -rf $(NAME)

#fclean

fclean: clean
	rm -rf $(OBJS)

#restart

re: fclean all

.PHONY: all fclean clean re
