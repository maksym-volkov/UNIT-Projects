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

static	void	null_all(t_board *board)
{
	int x;
	int y;

	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			board->map[y][x] = '.';
	}
	y = -1;
	while (++y < board->peace.y)
	{
		x = -1;
		while (++x < board->peace.x)
			board->peace.map[y][x] = '.';
	}
	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
			board->intmap.map[y][x] = 0;
	}
}

static	void	writing_peace(int *i, int y, char *line, t_board *board)
{
	int x;

	x = -1;
	*i = 0;
	get_next_line(0, &line);
	while (++x < board->peace.x)
	{
		if (line[*i] == '*')
			board->peace.sharps++;
		board->peace.map[y][x] = line[(*i)++];
	}
	board->peace.map[y][x] = '\0';
	free(line);
}

static	void	read_peace(t_board *board, char *line)
{
	int y;
	int i;

	y = -1;
	get_next_line(0, &line);
	board->peace.y = ft_atoi(&line[6]);
	board->peace.x = ft_atoi(&line[8]);
	board->peace.sharps = 0;
	free(line);
	board->peace.map = (char**)malloc(sizeof(char*) * (board->peace.y + 1));
	while (++y < board->peace.y)
		board->peace.map[y] = \
	(char*)malloc(sizeof(char) * (board->peace.x + 1));
	y = -1;
	while (++y < board->peace.y)
		writing_peace(&i, y, line, board);
}

static	int		read_map(t_board *board, char *line)
{
	int x;
	int y;
	int i;

	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		i = 4;
		get_next_line(0, &line);
		if (line[0] != '0')
			return (0);
		while (++x < board->max_x)
			board->map[y][x] = line[i++];
		board->map[y][x] = '\0';
		free(line);
	}
	return (1);
}

int				reading_all(t_board *board, char *line)
{
	board->result.res_x = 0;
	board->result.res_y = 0;
	board->result.resdis = 2147483647;
	if (!read_map(board, line))
		return (0);
	read_peace(board, line);
	inizialization_all(board);
	solution(board);
	null_all(board);
	free_peace(board);
	int_free(board);
	return (1);
}
