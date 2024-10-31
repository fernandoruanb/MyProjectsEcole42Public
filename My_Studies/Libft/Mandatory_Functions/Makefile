# Name of the Program or Library

NAME = libft.a

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

# SRCS

SRCS =  $(SRCDIR)/ft_isalpha.c\
	$(SRCDIR)/ft_isdigit.c\
	$(SRCDIR)/ft_isalnum.c\
	$(SRCDIR)/ft_isascii.c\
	$(SRCDIR)/ft_isprint.c\
	$(SRCDIR)/ft_strlen.c\
	$(SRCDIR)/ft_memset.c\
	$(SRCDIR)/ft_bzero.c\
	$(SRCDIR)/ft_memcpy.c\
	$(SRCDIR)/ft_memmove.c\
	$(SRCDIR)/ft_strlcpy.c\
	$(SRCDIR)/ft_strlcat.c\
	$(SRCDIR)/ft_toupper.c\
	$(SRCDIR)/ft_tolower.c\
	$(SRCDIR)/ft_strchr.c\
	$(SRCDIR)/ft_strncmp.c\
	$(SRCDIR)/ft_memchr.c\
	$(SRCDIR)/ft_memcmp.c\
	$(SRCDIR)/ft_strnstr.c

# SRCS .o

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# .o make

/%.o:/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# clear

clean:
	rm -f $(OBJS)

# full clear

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean all

.PHONY: all fclean clean re
