#Name of the program or library

NAME = phonebook

#COMPILERS AND FLAGS

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#DIRECTORIES

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  main.cpp\
	PhoneBook.cpp\
	Contact.cpp

#OBJS

OBJS = $(SRCS:%.cpp=%.o)

#MAIN

all: $(NAME)

# All the magic

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

re: fclean all

.PHONY: all fclean re clean
