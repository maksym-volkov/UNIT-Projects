/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:08:55 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 12:22:24 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

void		print_lines(t_base *base, int biggest)
{
	int		i;
	int		l;
	int		m;

	i = -1;
	while (++i < base->size && (m = -1))
	{
		if (base->lines[i])
			while (++m < base->lines[i])
				if (base->lines[i] > biggest)
					biggest = base->lines[i];
	}
	i = -1;
	while (++i < base->size && (m = -1))
	{
		if (base->lines[i] && (l = -1))
		{
			while (++l < (biggest - base->lines[i]))
				write(1, " ", 1);
			while (++m < base->lines[i])
				ft_printf(" |");
			ft_printf(" \n");
		}
	}
}

void		print_strategy(t_base *base)
{
	int i;

	i = -1;
	while (++i < base->size)
	{
		ft_printf("strategy line [%d]: %d\n", i + 1, base->calc_line[i]);
	}
}
