#Name of the program or the library

NAME = PmergeMe

#Compilers and flags

CC = c++
CFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

#Directories

SRCDIR = .
INCDIR = .

#SRCS

SRCS =	main.cpp\
	PmergeMe.cpp

#OBJS

OBJS = $(SRCS:.cpp=.o)

#Main

all: $(NAME)

#All the magic happens here

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

#.cpp -> .o

%o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# run tests

run: all
	#TEST 1
	-./PmergeMe 5
	@echo
	#TEST 2
	-./PmergeMe 1 2 3 4 5
	@echo
	#TEST 3
	-./PmergeMe 5 4 3 2 1
	@echo
	#TEST 4
	-@#./PmergeMe `shuf -i 1-100000 -n 3000 | tr '\n' ' '`
	@echo
	#TEST 5
	-./PmergeMe -5 10 20 || true
	@echo
	# TEST 6
	-./PmergeMe 10 A 20 || true
	@echo
	# TEST 7
	-./PmergeMe 10 20 10 30 || true
	@echo
	# TEST 8
	-./PmergeMe || true
	@echo
	#TEST 9
	-./PmergeMe 10 221v322 21 || true
	@echo
	#TEST 10
	-./PmergeMe "" || true
	@echo
	#TEST 11
	-./PmergeMe "                                                                            " || true
	@echo
	#TEST 12
	-./PmergeMe "              4                 5     2         10          12          99       " || true
	@echo
	#TEST 13
	-./PmergeMe 2 4 1 9 28 4728 123 34734 131874 1223 1918 24633 2111
	@echo
	#TEST 14
	-./PmergeMe 000000000000000000000002 0000000000000000000000000001 000000000000000000000000000003
	@echo
	#TEST 15
	-./PmergeMe 00000000000000000000023451 000000000000000000000000000000021 000000000000000000000000000002
	@echo
	#TEST 16
	-./PmergeMe 000000000000000000003442000 000000000031743810000 0000000000000000022234 00000000000234723800000 || true
	@echo
	#TEST 17
	-./PmergeMe 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999 || true
	@echo

#clean

clean:
	rm -rf $(NAME)

#fclean

fclean: clean
	rm -rf $(OBJS)

#restart

re: fclean all

.PHONY: all fclean clean re
