# Name of the program or library

NAME = libft.a

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .
OBJDIR = obj

# Archives .c

SRCS =  $(SRCDIR)/ft_isalpha.c\
	$(SRCDIR)/ft_isdigit.c\
	$(SRCDIR)/ft_isalnum.c\
	$(SRCDIR)/ft_isprint.c\
	$(SRCDIR)/ft_isascii.c\
	$(SRCDIR)/ft_strlen.c\
	$(SRCDIR)/ft_memset.c\
	$(SRCDIR)/ft_bzero.c\
	$(SRCDIR)/ft_strchr.c\
	$(SRCDIR)/ft_strrchr.c\
	$(SRCDIR)/ft_toupper.c\
	$(SRCDIR)/ft_tolower.c\
	$(SRCDIR)/ft_strncmp.c\
	$(SRCDIR)/ft_memchr.c\
	$(SRCDIR)/ft_atoi.c\
	$(SRCDIR)/ft_memcmp.c\
	$(SRCDIR)/ft_strlcpy.c\
	$(SRCDIR)/ft_strnstr.c

# Archives .o

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# .c -> .o

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Clear archives

clean:
	rm -rf $(OBJDIR)

# Full clean

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean $(NAME)
