# Nome da biblioteca

NAME = libft.a

# Compiladores e flags

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Diretórios

SRCDIR = srcs
INCDIR = includes
OBJDIR = obj

# Arquivos fonte

SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c

# Arquivos objeto

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Regra padrão

all: $(NAME)

#Regra processar biblioteca

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regra para pegar arquivos .o <- .c

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Limpar arquivos

clean:
	rm -rf $(OBJDIR)

#Limpar arquivos e também  biblioteca

fclean: clean
	rm -rf $(NAME)

# Recicla tudo e reinicia

re: fclean $(NAME)
