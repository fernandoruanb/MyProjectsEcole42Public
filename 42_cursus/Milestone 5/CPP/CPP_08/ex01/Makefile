#Name of the program or the library

NAME = span

#Compilers and flags

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  $(SRCDIR)/main.cpp\
	$(SRCDIR)/Span.cpp

#OBJS

OBJS =  $(SRCS:.cpp=.o)

#Main

all: $(NAME)

#All the magic happens here

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

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

.PHONY: fclean clean all re
