#Name of the program or the library

NAME = Warlock

#Compilers and flags

CC = c++
CFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  $(SRCDIR)/main.cpp\
	$(SRCDIR)/Warlock.cpp\
	$(SRCDIR)/ATarget.cpp\
	$(SRCDIR)/ASpell.cpp\
	$(SRCDIR)/Dummy.cpp\
	$(SRCDIR)/Fireball.cpp\
	$(SRCDIR)/Fwoosh.cpp\
	$(SRCDIR)/Polymorph.cpp\
	$(SRCDIR)/SpellBook.cpp\
	$(SRCDIR)/TargetGenerator.cpp\
	$(SRCDIR)/BrickWall.cpp

#OBJS

OBJS =  $(SRCS:.cpp=.o)

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

.PHONY: fclean clean all re
