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

#ifndef FILLER_H
# define FILLER_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct			s_counting
{
	int					count;
	int					count_x;
	int					figur;
}						t_counting;

typedef struct			s_result
{
	int					x;
	int					y;
	int					res_x;
	int					res_y;
	int					resdis;
}						t_result;

typedef struct			s_intmap
{
	int					**map;
	int					**maptmp;
	int					x;
	int					y;
	int					distance;
}						t_intmap;

typedef struct			s_peace
{
	char				**map;
	int					x;
	int					y;
	int					sharps;
}						t_peace;

typedef struct			s_board
{
	char				enemy;
	char				last;
	char				player;
	int					max_x;
	int					max_y;
	char				**map;
	t_peace				peace;
	t_intmap			intmap;
	t_result			result;
}						t_board;

int						reading_all(t_board *board, char *line);
void					inizialization_all(t_board *board);
void					solution(t_board *board);
void					int_free(t_board *board);
void					check_best_token(t_board *board);
void					next_distance(t_board *board, int x, int y);
int						next_point(t_board *board);
void					next_part_sharp(t_board *board, int *l, t_counting *c);
void					free_peace(t_board *board);
void					int_free(t_board *board);
void					enemy_first(t_board *board, int y);

#endif
