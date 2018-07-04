/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:34:13 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 05:37:56 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx_macos/mlx.h"

# define KEY_ESC 53

# define WIN_W 1000
# define WIN_H 600

# define PI 3.14159265

# define K_ESC 53
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define ARR_UP 126
# define ARR_DOWN 125
# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_NUM_1 83
# define K_NUM_3 85
# define K_NUM_4 86
# define K_NUM_6 88
# define K_NUM_7 89
# define K_NUM_9 92
# define K_SPACE 32

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				bits;
	int				size;
	int				end;
}					t_image;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_data
{
	char			*line;
	struct s_data	*next;
}					t_data;

typedef struct		s_fdf
{
	char			*line;
	int				dataSize;
	int				mapWidth;
	t_data			*data;
	t_coord			***map;
	t_coord			*center;
	t_image			*image;
	void			*mlx;
	void			*win;
}					t_fdf;

/*
**					main.c
*/

void				ft_error(char *str);

/*
**					inizialization.c
*/

t_data				*new_data(void);
t_coord				*new_coord(int x, int y, char *str);

/*
**					create_window.c
*/

void				create_window(t_fdf *fdf);
void				get_center(t_fdf *fdf);

/*
**					read_data.c
*/

void				read_data(t_fdf *fdf, char *file);
void				parse_coords(t_fdf *fdf);

/*
**					utilities.c
*/

int					array_len(char **array);
int					digit_len(int num);
int					is_color(char *str, int len);

/*
**					free_fdf.c
*/

void				free_split(char **str);

#endif




