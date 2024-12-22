# Name of the program or library

NAME = push_swap

# Compilers and flags

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra

# Directories

SRCDIR = src
OBJDIR = obj
INCDIR = includes
LIBFT_DIR = libft

# LIBFT

LIBFT = $(LIBFT_DIR)/libft.a

# SRCS

SRCS = $(shell find $(SRCDIR) -name "*.c")

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS) $(LIBFT)

# Clear

clean:
	rm -rf $(OBJDIR) 
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

# Full clear

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

# Restart

re: fclean all

# New function of my makefile NORMINETTE

norm:
	norminette $(SRCDIR) $(INCDIR) $(LIBFT_DIR)

.PHONY: all fclean re clean 
