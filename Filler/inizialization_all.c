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

static	void	check_neighbors(t_board *board, int x, int y, int num)
{
	if (x + 1 < board->max_x && board->intmap.map[y][x + 1] == 0)
		board->intmap.map[y][x + 1] = num + 1;
	if (y + 1 < board->max_y && x + 1 < board->max_x && \
		board->intmap.map[y + 1][x + 1] == 0)
		board->intmap.map[y + 1][x + 1] = num + 1;
	if (y + 1 < board->max_y && board->intmap.map[y + 1][x] == 0)
		board->intmap.map[y + 1][x] = num + 1;
	if (y + 1 < board->max_y && x - 1 > -1 && \
		board->intmap.map[y + 1][x - 1] == 0)
		board->intmap.map[y + 1][x - 1] = num + 1;
	if (x - 1 > -1 && board->intmap.map[y][x - 1] == 0)
		board->intmap.map[y][x - 1] = num + 1;
	if (y - 1 > -1 && x - 1 > -1 && board->intmap.map[y - 1][x - 1] == 0)
		board->intmap.map[y - 1][x - 1] = num + 1;
	if (y - 1 > -1 && board->intmap.map[y - 1][x] == 0)
		board->intmap.map[y - 1][x] = num + 1;
	if (y - 1 > -1 && x + 1 < board->max_x && \
		board->intmap.map[y - 1][x + 1] == 0)
		board->intmap.map[y - 1][x + 1] = num + 1;
}

static	void	init_enemy(t_board *board, int x, int y)
{
	if (x + 1 < board->max_x && board->intmap.map[y][x + 1] == 0)
		board->intmap.map[y][x + 1] = 1;
	if (y + 1 < board->max_y && x + 1 < board->max_x && \
		board->intmap.map[y + 1][x + 1] == 0)
		board->intmap.map[y + 1][x + 1] = 1;
	if (y + 1 < board->max_y && board->intmap.map[y + 1][x] == 0)
		board->intmap.map[y + 1][x] = 1;
	if (y + 1 < board->max_y && x - 1 > -1 && \
		board->intmap.map[y + 1][x - 1] == 0)
		board->intmap.map[y + 1][x - 1] = 1;
	if (x - 1 > -1 && board->intmap.map[y][x - 1] == 0)
		board->intmap.map[y][x - 1] = 1;
	if (y - 1 > -1 && x - 1 > -1 && board->intmap.map[y - 1][x - 1] == 0)
		board->intmap.map[y - 1][x - 1] = 1;
	if (y - 1 > -1 && board->intmap.map[y - 1][x] == 0)
		board->intmap.map[y - 1][x] = 1;
	if (y - 1 > -1 && x + 1 < board->max_x && \
		board->intmap.map[y - 1][x + 1] == 0)
		board->intmap.map[y - 1][x + 1] = 1;
}

static	void	init_map(t_board *board, int x, int y)
{
	int cur;

	cur = 1;
	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			if (board->intmap.map[y][x] == cur)
				check_neighbors(board, x, y, cur);
		if (y == board->max_y - 1 && cur < board->max_x + board->max_y)
		{
			cur++;
			y = -1;
			continue ;
		}
	}
}

static	void	init_second_map(t_board *board, int x, int y)
{
	y = -1;
	board->intmap.maptmp = (int**)malloc(sizeof(int*) * (board->max_y + 1));
	while (++y < board->max_y)
		board->intmap.maptmp[y] = \
	(int*)malloc(sizeof(int) * (board->max_x + 1));
	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			board->intmap.maptmp[y][x] = board->intmap.map[y][x];
	}
}

void			inizialization_all(t_board *board)
{
	int y;
	int x;

	y = -1;
	board->intmap.map = (int**)malloc(sizeof(int*) * (board->max_y + 1));
	while (++y < board->max_y)
		board->intmap.map[y] = (int*)malloc(sizeof(int) * (board->max_x + 1));
	y = -1;
	while (++y < board->max_y)
		enemy_first(board, y);
	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			if (board->intmap.map[y][x] == -1)
				init_enemy(board, x, y);
	}
	init_map(board, x, y);
	init_second_map(board, x, y);
}
