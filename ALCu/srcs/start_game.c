/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:21:54 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 12:24:44 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

static void		ending_game(int win, t_base *base)
{
	if (base->game_mode == 1 || base->game_mode == 2)
	{
		if (win == 1)
			ft_printf("\x1B[32m" "%s WON!\n",
				base->game_mode == 1 ? "Player" : "AI");
		if (win == 2)
			ft_printf("\x1B[32m" "%s WON!\n",
				base->game_mode == 1 ? "AI" : "Player");
	}
	else
		ft_printf("\x1B[32m" "%s WON!\n", win == 1 ?
			"Player One" : "Player Two");
}

static void		who_is_first(t_base *base)
{
	char	*line;
	int		num;

	ft_printf("Do you want to go first??[y/N]: ");
	while (1)
	{
		get_next_line(0, &line);
		if (!ft_strcmp(line, "y") || !ft_strcmp(line, "Y"))
			num = 1;
		else if (!ft_strcmp(line, "N") ||
			!ft_strcmp(line, "n") || !ft_strlen(line))
			num = 2;
		free(line);
		if (num == 1 || num == 2)
			break ;
		ft_printf("Invalid Input. Try again(1 or 2): ");
	}
}

static void		play_mode(t_base *base)
{
	int			choice;
	char		*line;

	while (1)
	{
		ft_printf("\x1B[34m\e[1m" "\tGAME MENU\n\n\t1.");
		ft_printf(" Player vs AI\n\t2. AI vs Player\n");
		ft_printf("\t3. Player vs Player\n");
		get_next_line(0, &line);
		if (!ft_strcmp(line, "1"))
			base->game_mode = 1;
		else if (!ft_strcmp(line, "2"))
			base->game_mode = 2;
		else if (!ft_strcmp(line, "3"))
			base->game_mode = 3;
		free(line);
		if (base->game_mode)
			break ;
		ft_printf("Wrong input. Try again\n");
	}
	ft_printf("%s vs %s mode!\n", (base->game_mode == 1 ||
		base->game_mode == 3) ? "Player" : "AI", (base->game_mode == 2 ||
			base->game_mode == 3) ? "Player" : "AI");
}

void			start_game(t_base *base)
{
	int		index;
	int		win;

	index = base->size - 1;
	play_mode(base);
	print_lines(base, 0);
	while (index >= 0 || base->lines[index])
	{
		index = base->game_mode == 1 ||
			base->game_mode == 3 ? player_one_turn(base, index) :
				ai_turn_one(base, index);
		if (index == -1 && (win = 2))
			break ;
		print_lines(base, 0);
		if (base->game_mode == 1 || base->game_mode == 2)
			index = base->game_mode == 1 ? ai_turn_two(base, index) :
				player_two_turn(base, index);
		else if (base->game_mode == 3)
			index = player_two_turn(base, index);
		if (index == -1 && (win = 1))
			break ;
		print_lines(base, 0);
	}
	ending_game(win, base);
}
