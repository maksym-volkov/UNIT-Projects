NAME = mvolkov.filler

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = 	main.c \
		reading_all.c \
		inizialization_all.c \
		solution.c \
		check_best_token.c \
		freeing.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS ?= -Wall -Wextra -Werror

FLAGS += -I./

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $@ $(FLAGS) $^

$(LIBFT):
	make -C $(LIBFT_DIR)/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o
	make -C $(LIBFT_DIR)/ fclean
	rm -f filler.trace
	rm -f vis

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: 
	gcc -Wall -Wextra -Werror -o vis vizi.c -I libft/ libft/libft.a

.PHONY: re clean fclean all