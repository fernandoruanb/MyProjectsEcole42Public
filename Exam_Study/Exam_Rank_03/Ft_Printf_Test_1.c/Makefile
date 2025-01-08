# Name of the program or the library

NAME = libftprintf.a

# Compilers and flags

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  $(SRCDIR)/ft_printf.c\
	$(SRCDIR)/parse_args.c\
	$(SRCDIR)/handle_specifiers.c\
	$(SRCDIR)/print_char.c\
	$(SRCDIR)/print_str.c\
	$(SRCDIR)/print_percentage.c\
	$(SRCDIR)/convert_int_to_str.c\
	$(SRCDIR)/convert_hex_to_str.c\
	$(SRCDIR)/ft_strlen.c

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

# clean

clean:
	rm -f $(OBJS);

# fclean

fclean: clean
	rm -f $(NAME);

# restart

re: fclean all

.PHONY: all fclean clean re
