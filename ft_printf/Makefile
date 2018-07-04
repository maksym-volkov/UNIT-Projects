NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = 	ft_printf.c \
				parse_start.c \
				do_types.c \
				numbers.c \
				utilities.c \
				utillities2.c \
				do_hex.c \
				do_octal.c \
				do_pointer.c \
				do_unicode.c \
				do_unicode_string.c \
				trash_func.c \
				parse_fl.c \
				numbers_print.c \
				octal_func.c \
				hex_print.c \
				
		
SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./libft/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBFT_DIR)/*.o
	ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)/

obj:
	mkdir obj/

obj/%.o: ./%.c | obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj/
	make -C $(LIBFT_DIR)/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re