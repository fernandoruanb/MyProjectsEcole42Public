#Name of the program of the library

NAME = philo

# Compilers and flags

CC = cc
CFLAGS = -g3 -pthread -Wall -Werror -Wextra

# Directories

SRCDIR = .
INCDIR = includes

# SRCS

SRCS = $(SRCDIR)/parsing/ft_atol.c\
       $(SRCDIR)/parsing/ft_isdigit.c\
       $(SRCDIR)/parsing/is_valid_number.c\
       $(SRCDIR)/parsing/parse_args.c\
       $(SRCDIR)/parsing/put_on_struct.c\
       $(SRCDIR)/philosophers/clean_die_mutexes.c\
       $(SRCDIR)/philosophers/clean_forks.c\
       $(SRCDIR)/philosophers/clean_philo_struct.c\
       $(SRCDIR)/philosophers/init_each_philo_die_mutex.c\
       $(SRCDIR)/philosophers/init_each_philo_fork.c\
       $(SRCDIR)/philosophers/init_each_philo_struct.c\
       $(SRCDIR)/philosophers/main.c\
       $(SRCDIR)/routine/anyone_death.c\
       $(SRCDIR)/routine/get_time.c\
       $(SRCDIR)/routine/has_eaten_every.c\
       $(SRCDIR)/routine/lets_go.c\
       $(SRCDIR)/routine/new_time.c\
       $(SRCDIR)/routine/try_fork_1.c\
       $(SRCDIR)/routine/try_fork_2.c\
       $(SRCDIR)/utils/ft_putendl_fd_0.c\
       $(SRCDIR)/utils/ft_putendl_fd_1.c\
       $(SRCDIR)/utils/ft_putendl_fd_n.c\
       $(SRCDIR)/utils/show_philo_struct.c\
       $(SRCDIR)/routine/eat_sleep.c\
       $(SRCDIR)/routine/die.c

# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(NAME)

# .c -> .o

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS)

# Clean

clean:
	rm -f $(OBJS)

# Full clean

fclean: clean
	rm -f $(NAME)

# Restart

re: fclean $(NAME)

.PHONY: NAME all clean fclean re
