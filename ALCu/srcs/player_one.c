/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:21:54 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 12:18:25 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

static	int		check_remain(t_base *base, int index, int *num)
{
	*num > base->lines[index] ?
		ft_printf("\x1B[31m" \
		"Too many matches for this line. Try again(1 - 3): ") : 1;
	if (*num > base->lines[index])
	{
		*num = 0;
		return (1);
	}
	return (0);
}

int				player_one_turn(t_base *base, int index)
{
	int		num;
	char	*line;

	num = 0;
	ft_printf("\x1B[31m" "Player One turn(1 - 3): ");
	while (num < 1 || num > 3)
	{
		get_next_line(0, &line);
		num = ft_atoi(line);
		free(line);
		num < 1 || num > 3 ?
			ft_printf("\x1B[31m" "Invalid Input. Try again(1 - 3): ") : 1;
		if (num >= 1 && num <= 3 && check_remain(base, index, &num))
			continue ;
	}
	base->lines[index] -= num;
	if (base->lines[index] > 0)
		return (index);
	return (index - 1);
}
