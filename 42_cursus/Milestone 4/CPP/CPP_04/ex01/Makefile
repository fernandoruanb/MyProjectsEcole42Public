#Name of the program or the library

NAME = Brain

#Compilers and flags

CC = c++
CFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  main.cpp\
	Dog.cpp\
	Cat.cpp\
	Animal.cpp\
	Brain.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp

#OBJS

OBJS = $(SRCS:.cpp=.o)

#Main

all: $(NAME)

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

.PHONY: clean fclean re all
