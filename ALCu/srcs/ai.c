/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:35:43 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 11:42:43 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

static int		first(int m)
{
	int		res;

	res = 0;
	if (m == 4)
		return (3);
	else if (m == 3)
		return (2);
	else if (m == 2)
		return (1);
	else if (is_4k_plus_one(m) || m == 1)
		return (1);
	while (m && !is_4k_plus_one(m))
	{
		m--;
		res++;
	}
	return (res);
}

static int		second(int m)
{
	int		res;

	res = 0;
	if (m == 5)
		return (1);
	else if (m == 3)
		return (3);
	else if (m == 2)
		return (2);
	else if (m == 1)
		return (1);
	if (is_4k_plus_one(m))
		return (1);
	while (m && !is_4k_plus_one(m))
	{
		m--;
		res++;
	}
	res++;
	return (res > 3 ? 1 : res);
}

int				ai_turn_one(t_base *base, int index)
{
	int		r1;
	int		r2;

	r1 = first(base->lines[index]);
	r2 = second(base->lines[index]);
	if (!index || (index && base->calc_line[index - 1] == 1))
	{
		ft_printf("\x1B[31m" "AI turn(1 - 3): %d\n", r1);
		base->lines[index] = base->lines[index] - r1;
	}
	else if (index && base->calc_line[index - 1] == 2)
	{
		ft_printf("\x1B[31m" "AI turn(1 - 3): %d\n", r2);
		base->lines[index] = base->lines[index] - r2;
	}
	if (!base->lines[index] && index)
		index -= 1;
	else if (!base->lines[index] && !index)
		index = -1;
	return (index);
}

int				ai_turn_two(t_base *base, int index)
{
	int		r1;
	int		r2;

	r1 = first(base->lines[index]);
	r2 = second(base->lines[index]);
	if (!index || (index && base->calc_line[index - 1] == 1))
	{
		ft_printf("\x1B[34m" "AI turn(1 - 3): %d\n", r1);
		base->lines[index] = base->lines[index] - r1;
	}
	else if (index && base->calc_line[index - 1] == 2)
	{
		ft_printf("\x1B[34m" "AI turn(1 - 3): %d\n", r2);
		base->lines[index] = base->lines[index] - r2;
	}
	if (!base->lines[index] && index)
		index -= 1;
	else if (!base->lines[index] && !index)
		index = -1;
	return (index);
}
