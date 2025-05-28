#Name of the program or the library

NAME = Warlock

#Compilers and flags

CC = c++
CFLAGS = -g3 -Wall -Werror -Werror -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  $(SRCDIR)/main.cpp\
	$(SRCDIR)/Warlock.cpp\
	$(SRCDIR)/Dummy.cpp\
	$(SRCDIR)/Fwoosh.cpp\
	$(SRCDIR)/ATarget.cpp\
	$(SRCDIR)/ASpell.cpp

#OBJS

OBJS =  $(SRCS:.cpp=.o)

#Main

all: $(NAME)

#All the magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#.cpp = .o

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
