#Name of the program or the library

NAME = your_note

#Compilers and flags

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  main.cpp\
	Pessoa.cpp\
	List.cpp

#OBJS

OBJS = $(SRCS:%.cpp=%.o)

#Main

all: $(NAME)

#The magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#clean

clean:
	rm -rf $(OBJS)

#fclean

fclean: all clean
	rm -rf $(NAME)

#restart

re: all fclean

.PHONY: all fclean clean re
