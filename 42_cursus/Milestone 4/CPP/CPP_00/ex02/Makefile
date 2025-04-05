#Name of the program or the library

NAME = account

#Compilers and flags

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  Account.cpp\
	tests.cpp

#OBJS

OBJS = $(SRCS:%.cpp=%.o)

#Main

all: $(NAME)

#All the magic

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#Compilation part

%.o:%.cpp
	$(CC) $(CFLAGS) -c $? -o $@

#clean

clean:
	rm -rf $(OBJS)

#fclean

fclean: clean
	rm -rf $(NAME)

#restart

re: all fclean

.PHONY: fclean all clean re
