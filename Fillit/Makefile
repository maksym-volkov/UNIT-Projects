# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fillit                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 14:04:46 by mvolkov           #+#    #+#              #
#    Updated: 2017/11/15 14:04:51 by mvolkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c reading.c valid.c prepearing.c ft_map_bigger.c solution.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean
	
re: fclean all
	@make -C libft/ re