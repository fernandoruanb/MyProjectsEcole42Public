#Name of the program or the library

NAME = bureaucrat_abstract_form

#Compilers and flags

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =  $(SRCDIR)/main.cpp\
	$(SRCDIR)/Bureaucrat.cpp\
	$(SRCDIR)/AForm.cpp\
	$(SRCDIR)/ShrubberyCreationForm.cpp\
	$(SRCDIR)/RobotomyRequestForm.cpp\
	$(SRCDIR)/PresidentialPardonForm.cpp

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
	rm -rf *_shrubbery

#restart

re: fclean all

.PHONY: all fclean clean re
