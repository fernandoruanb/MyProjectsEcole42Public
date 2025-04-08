#Name of the program or library

NAME = megaphone

#Flags to compile

CC = c++
CPPFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

#Main

all: $(NAME)

#.cpp -> .o

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

.PHONY: fclean clean re all
