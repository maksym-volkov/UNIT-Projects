/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	mem_free(t_board *board)
{
	int y;

	y = -1;
	while (++y < board->max_y)
		free(board->map[y]);
	free(board->map);
}

static	void	mem_aloc_map(t_board *board)
{
	int y;

	y = -1;
	board->map = (char**)malloc(sizeof(char*) * (board->max_y + 1));
	while (++y < board->max_y)
		board->map[y] = (char*)malloc(sizeof(char) * (board->max_x + 1));
}

static	void	send_result(t_board *board, char *line)
{
	ft_putnbr(board->result.res_y);
	ft_putchar(' ');
	ft_putnbr(board->result.res_x);
	ft_putchar('\n');
	if (get_next_line(0, &line) > 0)
		free(line);
	if (get_next_line(0, &line) > 0)
		free(line);
}

int				main(void)
{
	char		*line;
	t_board		board;

	line = NULL;
	ft_bzero(&board, sizeof(t_board));
	get_next_line(0, &line);
	board.player = 'O';
	board.enemy = 'X';
	line[10] == '2' ? board.player = 'X' : 1;
	line[10] == '2' ? board.enemy = 'O' : 1;
	board.last = board.enemy + 32;
	free(line);
	get_next_line(0, &line);
	board.max_y = ft_atoi(&line[8]);
	board.max_x = ft_atoi(&line[11]);
	free(line);
	get_next_line(0, &line);
	free(line);
	mem_aloc_map(&board);
	while (reading_all(&board, line))
		send_result(&board, line);
	mem_free(&board);
	return (0);
}
