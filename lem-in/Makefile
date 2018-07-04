NAME = lem-in

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = 	main.c \
		read_input.c \
		inizializing.c \
		utilities.c \
		read_links.c \
		solution.c \
		find_path.c \
		print_map.c \
		free_lemin.c \

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

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
