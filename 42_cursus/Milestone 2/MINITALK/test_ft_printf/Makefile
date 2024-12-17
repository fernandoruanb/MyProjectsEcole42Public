# Name of the program or the library

NAME = libftprintf.a

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  $(SRCDIR)/ft_printf.c\
	$(SRCDIR)/parse_format.c\
	$(SRCDIR)/handle_specifier.c\
	$(SRCDIR)/print_char.c\
	$(SRCDIR)/print_str.c\
	$(SRCDIR)/print_percentage.c\
	$(SRCDIR)/convert_int_to_str.c

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# .c -> .o

%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# clear

clean:
	rm -f $(OBJS)

# full clear

fclean: clean
	rm -f $(NAME)

# restart

re: all fclean

.PHONY: all fclean clean re
