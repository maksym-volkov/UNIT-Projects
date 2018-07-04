NAME	= fdf

SRC = 	main.c \
		inizialization.c \
		read_data.c \
		utilities.c \
		free_fdf.c \
		create_window.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra

# mlx library
MLX		= ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx_macos
MLX_LNK	= -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: re clean fclean all
