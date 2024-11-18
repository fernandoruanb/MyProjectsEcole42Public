# Name of the program or library

NAME = libft.a

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = .

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
	$(SRCDIR)/ft_strnstr.c\
	$(SRCDIR)/ft_strdup.c\
	$(SRCDIR)/ft_putchar_fd.c\
	$(SRCDIR)/ft_putstr_fd.c\
	$(SRCDIR)/ft_putendl_fd.c\
	$(SRCDIR)/ft_putnbr_fd.c\
	$(SRCDIR)/ft_calloc.c\
	$(SRCDIR)/ft_itoa.c\
	$(SRCDIR)/ft_memmove.c\
	$(SRCDIR)/ft_strlcat.c\
	$(SRCDIR)/ft_memcpy.c\
	$(SRCDIR)/ft_striteri.c\
	$(SRCDIR)/ft_strmapi.c\
	$(SRCDIR)/ft_strjoin.c\
	$(SRCDIR)/ft_substr.c\
	$(SRCDIR)/ft_strtrim.c\
	$(SRCDIR)/ft_split.c\
	$(SRCDIR)/get_next_line.c\
	$(SRCDIR)/ft_printf.c\
	$(SRCDIR)/parse_format.c\
	$(SRCDIR)/convert_hex_to_str.c\
	$(SRCDIR)/print_char.c\
	$(SRCDIR)/print_str.c\
	$(SRCDIR)/handle_specifier.c\
	$(SRCDIR)/convert_int_to_str.c\
	$(SRCDIR)/print_percentage.c\
	$(SRCDIR)/convert_ptr_to_str.c\
	$(SRCDIR)/convert_unsigned_to_str.c\
	$(SRCDIR)/rev_print.c\
	$(SRCDIR)/first_word.c\
	$(SRCDIR)/fizzbuzz.c\
	$(SRCDIR)/ft_putstr.c\
	$(SRCDIR)/ft_strcpy.c\
	$(SRCDIR)/ultimate_ft_strlen.c\
	$(SRCDIR)/ft_swap.c\
	$(SRCDIR)/repeat_alpha.c\
	$(SRCDIR)/rot_13.c\
	$(SRCDIR)/rotone.c\
	$(SRCDIR)/search_and_replace.c\
	$(SRCDIR)/ulstr.c\
	$(SRCDIR)/alpha_mirror.c\
	$(SRCDIR)/camel_to_snake.c\
	$(SRCDIR)/do_op.c\
	$(SRCDIR)/ulstr_v2.c\
	$(SRCDIR)/ft_strcspn.c\
	$(SRCDIR)/ft_strpbrk.c

# BONUS SRCS

BONUS_SRCS = 	$(SRCDIR)/ft_lstnew_bonus.c\
		$(SRCDIR)/ft_lstadd_front_bonus.c\
		$(SRCDIR)/ft_lstsize_bonus.c\
		$(SRCDIR)/ft_lstlast_bonus.c\
		$(SRCDIR)/ft_lstadd_back_bonus.c\
		$(SRCDIR)/ft_lstdelone_bonus.c\
		$(SRCDIR)/ft_lstclear_bonus.c\
		$(SRCDIR)/ft_lstiter_bonus.c\
		$(SRCDIR)/ft_lstmap_bonus.c

# Archives .o

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:$(SRCDIR)/%.c=%.o)

# Check bonus relink

ifeq ($(findstring bonus,$(MAKECMDGOALS)),bonus)
	OBJS += $(BONUS_OBJS)
endif

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Main bonus

bonus: $(NAME)

# .c -> .o

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Clear archives

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Full clean

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean $(NAME)

.PHONY: all clean fclean re bonus

