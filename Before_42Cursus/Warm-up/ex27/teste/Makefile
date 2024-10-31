# Nome do programa ou biblioteca

NAME = ft_display_file

# Compiladores e flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Onde está o nosso SRC ou SRCS? Arquivos fontes

SRC = ft_display_file.c

# E nossos arquivos .o

OBJ = $(SRC:.c=.o)

# Vamos para a regra principal

all: $(NAME)

# E a união da mesma gerando os .o

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Limpar arquivos

clean:
	rm -rf $(OBJ)

# Limpar tudo

fclean: clean
	rm -rf $(NAME)

# Reciclagem

re: fclean all
