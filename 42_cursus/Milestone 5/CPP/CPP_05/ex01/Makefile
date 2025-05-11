#Name of the program or the library

NAME = bureacrat

#Compilers and flags

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  $(SRCDIR)/Bureaucrat.cpp\
	$(SRCDIR)/main.cpp\
	$(SRCDIR)/Form.cpp

#OBJS

OBJS = $(SRCS:.cpp=.o)

#Main

all: $(NAME)

# all the magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#.cpp -> .o

%o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#clean

clean:
	rm -rf $(OBJS)

#fclean

fclean: clean
	rm -rf $(NAME)

#restart

re: fclean all

.PHONY: all fclean re clean
