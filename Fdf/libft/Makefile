# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 15:27:55 by mvolkov           #+#    #+#              #
#    Updated: 2017/10/26 15:27:55 by mvolkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strrchr.c \
ft_strstr.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c \
ft_putnbr.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_memalloc.c \
ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_strupcase.c ft_strlowcase.c ft_factorial.c \
ft_power.c ft_fibonacci.c ft_sqrt.c get_next_line.c ft_printf.c parse_start.c \
do_types.c numbers.c utilities.c utillities2.c do_hex.c do_octal.c do_pointer.c \
do_unicode.c do_unicode_string.c trash_func.c parse_fl.c numbers_print.c \
octal_func.c hex_print.c atoi_base.c\

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC)  $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all