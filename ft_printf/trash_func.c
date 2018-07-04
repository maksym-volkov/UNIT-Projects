/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:11:47 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:25:43 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	trash(t_qualifiers q, int *res, unsigned char c)
{
	int tmp;

	tmp = q.width - 1;
	*res = 1;
	q.width > 1 ? *res = q.width : 1;
	if (q.width < 2)
		write(1, &c, 1);
	else if (q.flags[2] == '-' && q.width > 1)
	{
		write(1, &c, 1);
		while (tmp--)
			write(1, " ", 1);
	}
	else if (q.flags[2] != '-' && q.width > 1)
	{
		while (tmp-- && q.flags[1] != '0')
			write(1, " ", 1);
		tmp++;
		while (tmp-- && q.flags[1] == '0')
			write(1, "0", 1);
		write(1, &c, 1);
	}
}

void			trash_flag(char flag, t_qualifiers *q)
{
	if (flag == '0')
		q->flags[1] = '0';
	if (flag == '-')
		q->flags[2] = '-';
}

int				trash_func(char *f, unsigned char end)
{
	t_qualifiers	q;
	int				i;
	int				res;

	i = 0;
	iniz(&q);
	while (f[i] != end)
		trash_parse(&q, &i, f);
	trash(q, &res, end);
	return (res);
}
