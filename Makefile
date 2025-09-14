# Nom de l'exécutable
NAME = pipex

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g

SRC_DIR = src
SRC =	$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/ft_init_pipex.c \
		$(SRC_DIR)/ft_exec.c \
		$(SRC_DIR)/ft_parse_args.c \
		$(SRC_DIR)/ft_parse_cmds.c \
		$(SRC_DIR)/ft_check_args.c \
		$(SRC_DIR)/ft_cleanup.c \
	
OBJ = $(SRC:.c=.o)

# Répertoire de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compilation
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "libft OK"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) > /dev/null
	@echo "pipex OK"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all