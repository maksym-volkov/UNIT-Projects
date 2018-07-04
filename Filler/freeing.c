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

void	enemy_first(t_board *board, int y)
{
	int x;

	x = -1;
	while (++x < board->max_x)
		if (board->map[y][x] == board->enemy || board->map[y][x] == board->last)
			board->intmap.map[y][x] = -1;
		else
			board->intmap.map[y][x] = 0;
}

void	free_peace(t_board *board)
{
	int i;

	i = -1;
	while (++i < board->peace.y)
		free(board->peace.map[i]);
	free(board->peace.map);
}

void	int_free(t_board *board)
{
	int y;

	y = -1;
	while (++y < board->max_y)
		free(board->intmap.map[y]);
	free(board->intmap.map);
	y = -1;
	while (++y < board->max_y)
		free(board->intmap.maptmp[y]);
	free(board->intmap.maptmp);
}
