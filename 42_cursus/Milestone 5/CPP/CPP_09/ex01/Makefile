#Name of the program or the library

NAME = RPN

#Compilers and flags

CC = c++
CFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  main.cpp\
	RPN.cpp

#OBJS

OBJS =  $(SRCS:.cpp=.o)

#Main

all: $(NAME)

#tests

run: all
	-./RPN "2 3 +"
	-./RPN "5 1 2 + 4 * + 3 -"
	-./RPN "8 2 /"
	-./RPN "8 0 /" || true
	-./RPN "5 2 %" || true
	-./RPN "5      1  2    +    *" || true
	-./RPN "+" || true
	-./RPN "5 5 + +" || true
	-./RPN "2 3 + a b c" || true
	-./RPN "" || true
	-./RPN "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 2 +"
	-./RPN "9 3 / 2 1 + * 4 - 7 +"
	-./RPN "1 2 * 2 / 2 * 2 4 - +"
	-./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	-./RPN "7 7 * 7 -"
	-./RPN "(1 + 1)" || true
	-./RPN "1 2 3 7 5 6 8" || true
	-./RPN "000000000000002 2 +"
	-./RPN "000000000000000 2 +"
	-./RPN "000000000000020 2 +" || true
	-./RPN "2 2 + 00000000002 - 2 +"

#All the magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#.cpp -> .o
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#clean

clean:
	rm -rf $(OBJS)

#fclean

fclean: clean
	rm -rf $(NAME)

#restart

re: fclean all

.PHONY: all fclean clean re
