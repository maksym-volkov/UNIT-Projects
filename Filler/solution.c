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

static	void	check_end(t_board *board, t_counting *c, int *l)
{
	if (c->count_x == board->peace.sharps && c->count != 1)
	{
		next_part_sharp(board, l, c);
		c->count_x = 0;
	}
	if (c->count_x == board->peace.sharps && c->count == 1)
	{
		check_best_token(board);
		next_part_sharp(board, l, c);
		c->count_x = 0;
		board->intmap.maptmp[board->intmap.y][board->intmap.x] = 2147483647;
	}
	if (c->count > 1)
	{
		next_part_sharp(board, l, c);
		c->count_x = 0;
	}
}

static	void	check_true_star(t_board *board, int i, int l, t_counting *c)
{
	if (board->peace.map[l][i] == '*' && \
		board->map[board->result.y + l][board->result.x + i] == board->player)
	{
		c->count_x++;
		c->count++;
	}
	else if (board->peace.map[l][i] == '*' && \
		board->map[board->result.y + l][board->result.x + i] == '.')
		c->count_x++;
}

static	int		after_next_point(t_board *board, t_counting *c, int *l)
{
	board->intmap.maptmp[board->intmap.y][board->intmap.x] = 2147483647;
	if (!next_point(board))
		return (0);
	c->count = 0;
	*l = 0;
	c->count_x = 0;
	return (1);
}

static	void	find_place(t_board *b, t_counting *c, int l, int i)
{
	while (++l < b->peace.y && (i = -1))
	{
		if ((b->intmap.y - b->result.y) > b->peace.y)
			if (!after_next_point(b, c, &l))
				return ;
		while (++i < b->peace.x)
		{
			if (b->peace.map[l][i] == '*' && ((b->result.y + l < 0 || \
				b->result.y + l > b->max_y - 1) || \
				(b->result.x + i < 0 || b->result.x + i > b->max_x - 1)))
			{
				next_part_sharp(b, &l, c);
				break ;
			}
			check_true_star(b, i, l, c);
			if (b->peace.map[l][i] == '*' && \
				(b->map[b->result.y + l][b->result.x + i] ==\
			b->enemy || b->map[b->result.y + l][b->result.x + i] == b->last))
			{
				next_part_sharp(b, &l, c);
				break ;
			}
		}
		check_end(b, c, &l);
	}
}

void			solution(t_board *board)
{
	t_counting	c;
	int			y;
	int			x;

	y = -1;
	c.figur = 0;
	c.count = 0;
	c.count_x = 0;
	board->intmap.distance = 2147483647;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			if (board->map[y][x] == board->player && \
				board->intmap.distance >= board->intmap.maptmp[y][x])
			{
				board->intmap.x = x;
				board->intmap.y = y;
				board->intmap.distance = board->intmap.maptmp[y][x];
			}
	}
	board->result.x = board->intmap.x;
	board->result.y = board->intmap.y;
	y = -1;
	find_place(board, &c, y, x);
}
