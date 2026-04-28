CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFT = ./libft/libft.a

SRC = error_free.c main.c \
	  operations_push.c operations_reverse_rotate.c \
	  operations_rotate.c operations_swap.c \
	  push_swap.c sort_big.c \
	  sort_small.c stack_init.c \
	  parsing.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re