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

SRCS = $(wildcard $(SRCDIR)/*.c)

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
