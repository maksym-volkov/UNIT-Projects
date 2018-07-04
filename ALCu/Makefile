# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 01:17:41 by afarapon          #+#    #+#              #
#    Updated: 2018/03/11 12:49:23 by afarapon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

CC = gcc

KEYS = -Wall -Wextra -Werror

FLAGS = -flto -O3 \
	-I./includes

IDIR = ./includes

LIBDIR = ./libft

LIBFT = $(LIBDIR)/libft.a

SRCDIR = srcs

SRC = \
	main.c \
	service.c \
	read_input.c \
	start_game.c \
	player_one.c \
	player_two.c \
	strategy.c \
	num_checker.c \
	printers.c \
	ai.c \

_DEPS = m.h

OBJ = $(SRC:.c=.o)

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(LIBFT) $(OBJ)
	@cp libft/libft.a ./$(NAME)
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) libft/libft.a

$(LIBFT):
	@make -C $(LIBDIR)

clean:
	@/bin/rm -rf *.o
	@/bin/rm -rf libft/*.o

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf libft/libft.a

re: fclean all
