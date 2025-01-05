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

SRCS =  $(SRCDIR)/operations/ft_pa.c\
	$(SRCDIR)/operations/ft_pb.c\
	$(SRCDIR)/operations/ft_ra.c\
	$(SRCDIR)/operations/ft_rb.c\
	$(SRCDIR)/operations/ft_rra.c\
	$(SRCDIR)/operations/ft_rrb.c\
	$(SRCDIR)/operations/ft_rr.c\
	$(SRCDIR)/operations/ft_rrr.c\
	$(SRCDIR)/operations/ft_sa.c\
	$(SRCDIR)/operations/ft_sb.c\
	$(SRCDIR)/operations/ft_ss.c\
	$(SRCDIR)/ordenation/check_rr.c\
	$(SRCDIR)/ordenation/check_rrr.c\
	$(SRCDIR)/ordenation/check_sorted_b.c\
	$(SRCDIR)/ordenation/check_sorted.c\
	$(SRCDIR)/ordenation/choose_algoritm.c\
	$(SRCDIR)/ordenation/choose_best_movement_a.c\
	$(SRCDIR)/ordenation/choose_best_movement.c\
	$(SRCDIR)/ordenation/find_best_match.c\
	$(SRCDIR)/ordenation/find_location_max_a.c\
	$(SRCDIR)/ordenation/find_location_max_b.c\
	$(SRCDIR)/ordenation/find_next_number.c\
	$(SRCDIR)/ordenation/find_smallest_num.c\
	$(SRCDIR)/ordenation/five_elements.c\
	$(SRCDIR)/ordenation/four_elements.c\
	$(SRCDIR)/ordenation/get_action.c\
	$(SRCDIR)/ordenation/get_least_moves_b.c\
	$(SRCDIR)/ordenation/get_least_moves.c\
	$(SRCDIR)/ordenation/get_rotates_cost.c\
	$(SRCDIR)/ordenation/high_numbers_generic.c\
	$(SRCDIR)/ordenation/low_numbers_generic.c\
	$(SRCDIR)/ordenation/max_a_determine.c\
	$(SRCDIR)/ordenation/max_b_determine.c\
	$(SRCDIR)/ordenation/max_b_to_top.c\
	$(SRCDIR)/ordenation/min_a_determine.c\
	$(SRCDIR)/ordenation/min_b_determine.c\
	$(SRCDIR)/ordenation/move_to_a.c\
	$(SRCDIR)/ordenation/move_to_b.c\
	$(SRCDIR)/ordenation/new_high_numbers_generic.c\
	$(SRCDIR)/ordenation/new_high_numbers_generic_v2.c\
	$(SRCDIR)/ordenation/push_all_to_a.c\
	$(SRCDIR)/ordenation/show_stacks.c\
	$(SRCDIR)/ordenation/six_elements.c\
	$(SRCDIR)/ordenation/sort_a.c\
	$(SRCDIR)/ordenation/three_elements.c\
	$(SRCDIR)/ordenation/two_elements.c\
	$(SRCDIR)/parsing/count_all_numbers.c\
	$(SRCDIR)/parsing/ft_atoi_check.c\
	$(SRCDIR)/parsing/is_nothing.c\
	$(SRCDIR)/parsing/is_number.c\
	$(SRCDIR)/parsing/is_sorted.c\
	$(SRCDIR)/parsing/init_stack.c\
	$(SRCDIR)/parsing/parse_args.c\
	$(SRCDIR)/push_swap/main.c\
	$(SRCDIR)/utils/ft_putendl_fd_0.c\
	$(SRCDIR)/utils/ft_putendl_fd_1.c\
	$(SRCDIR)/utils/ft_putendl_fd_n.c
	
# OBJS

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Main

all: $(NAME)

# Compile %.o

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Main rule

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@mkdir -p $(OBJDIR)
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

.PHONY: all fclean re clean norm 
