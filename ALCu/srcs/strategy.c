/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:41:52 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 12:23:28 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

static int			hardcode(int a)
{
	if (a == 3 || a == 2)
		return (1);
	return (0);
}

void				make_ai_strategy(t_base *base, int i)
{
	while (++i < base->size)
	{
		if (hardcode(base->lines[i]) && (base->calc_line[i] = 1))
			continue ;
		if (!i && base->lines[i] != 1 &&
			(!is_4k_plus_one(base->lines[i]) || base->lines[i] < 5))
			base->calc_line[i] = 1;
		else if (!i)
			base->calc_line[i] = 2;
		if (i > 0)
		{
			if (base->calc_line[i - 1] == 1 &&
				(!is_4k_plus_one(base->lines[i]) ||
					base->lines[i] == 4) && base->lines[i] != 1)
				base->calc_line[i] = 1;
			else if (base->calc_line[i - 1] == 1)
				base->calc_line[i] = 2;
			if (base->calc_line[i - 1] == 2 &&
				(is_4k_plus_one(base->lines[i]) || base->lines[i] == 1))
				base->calc_line[i] = 1;
			else if (base->calc_line[i - 1] == 2)
				base->calc_line[i] = 2;
		}
	}
}
