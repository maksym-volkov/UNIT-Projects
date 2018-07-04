/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	next_part_sharp(t_board *board, int *l, t_counting *c)
{
	c->figur++;
	board->result.x--;
	if (c->figur == board->peace.x)
	{
		board->result.x += c->figur;
		board->result.y--;
		c->figur = 0;
	}
	*l = -1;
	c->count = 0;
	c->count_x = 0;
}

int		next_point_part_2(t_board *board)
{
	board->intmap.distance = \
	board->intmap.maptmp[board->intmap.y][board->intmap.x];
	if (board->intmap.maptmp[board->intmap.y][board->intmap.x] == \
		2147483647 || (board->result.resdis != 2147483647 && \
			(board->peace.y > 30 || board->peace.x > 30)))
		return (0);
	board->result.x = board->intmap.x;
	board->result.y = board->intmap.y;
	return (1);
}

int		next_point(t_board *board)
{
	int x;
	int y;

	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			if (board->map[y][x] == board->player && \
				board->intmap.distance == board->intmap.maptmp[y][x])
			{
				board->intmap.x = x;
				board->intmap.y = y;
				board->intmap.distance = board->intmap.maptmp[y][x];
			}
	}
	y = -1;
	if (board->intmap.maptmp[board->intmap.y][board->intmap.x] == 2147483647)
		next_distance(board, x, y);
	if (!next_point_part_2(board))
		return (0);
	return (1);
}

void	check_best_token(t_board *board)
{
	int tmp;
	int x;
	int y;

	tmp = 0;
	y = -1;
	while (++y < board->peace.y)
	{
		x = -1;
		while (++x < board->peace.x)
			if ((board->result.y + y >= 0 && board->result.y + y <=\
			board->max_y - 1) && (board->result.x + x >= 0 || \
			board->result.x + x <= board->max_x - 1))
				if (board->peace.map[y][x] == '*')
					tmp += \
				board->intmap.map[board->result.y + y][board->result.x + x];
	}
	if (tmp <= board->result.resdis)
	{
		board->result.res_y = board->result.y;
		board->result.res_x = board->result.x;
		board->result.resdis = tmp;
	}
}

void	next_distance(t_board *board, int x, int y)
{
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			if (board->map[y][x] == board->player && \
				(board->intmap.distance + 1) == board->intmap.maptmp[y][x])
			{
				board->intmap.x = x;
				board->intmap.y = y;
			}
	}
}
