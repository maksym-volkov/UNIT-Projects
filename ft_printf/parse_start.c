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

void	iniz(t_qualifiers *q)
{
	q->width = 0;
	q->precision = -1;
	q->length = '0';
	q->flags[0] = '@';
	q->flags[1] = '@';
	q->flags[2] = '@';
	q->flags[3] = '@';
	q->flags[4] = '@';
}

int		check_type(t_qualifiers q, va_list args)
{
	int res;

	res = 0;
	if (q.type == 's' && q.length != 'l')
		do_string(q, args, &res);
	else if (q.type == 'c' && q.length != 'l')
		do_char(q, args, &res);
	else if (q.type == 'i' || q.type == 'd' || q.type == 'D')
		do_i_or_d(q, args, &res);
	else if (q.type == 'u' || q.type == 'U')
		do_u_or_u(q, args, &res);
	else if (q.type == 'x' || q.type == 'X')
		do_x_or_x(q, args, &res);
	else if (q.type == 'o' || q.type == 'O')
		do_o_or_o(q, args, &res);
	else if (q.type == 'p')
		do_p(q, args, &res);
	else if (q.type == 'C' || (q.type == 'c' && q.length == 'l'))
		do_unicode_c(q, args, &res);
	else if (q.type == 'S' || (q.type == 's' && q.length == 'l'))
		do_unicode_s(q, args, &res);
	return (res);
}

void	parse_flag(char flag, t_qualifiers *q)
{
	if (flag == '#')
		q->flags[0] = '#';
	if (flag == '0')
		q->flags[1] = '0';
	if (flag == '-')
		q->flags[2] = '-';
	if (flag == '+')
		q->flags[3] = '+';
	if (flag == ' ')
		q->flags[4] = ' ';
}

int		true_parsing(char *f, char end, va_list args)
{
	t_qualifiers	q;
	int				i;

	i = 0;
	iniz(&q);
	while (f[i] != end)
	{
		parse_fl(&q, &i, f);
		parse_pw(&q, &i, f);
	}
	q.type = end;
	return (check_type(q, args));
}

char	*parse_start(char *f, va_list args, int *res)
{
	int i;

	i = 0;
	while (f[i] == '#' || f[i] == '0' || f[i] == '-' || f[i] == '+'\
	|| f[i] == '.' || (f[i] >= '0' && f[i] <= '9') || f[i] == 'h'\
	|| f[i] == 'l' || f[i] == 'j' || f[i] == 'z' || f[i] == ' ')
		i++;
	if (f[i] == 's' || f[i] == 'S' || f[i] == 'p' || f[i] == 'd'\
	|| f[i] == 'D' || f[i] == 'i' || f[i] == 'o' || f[i] == 'O'\
	|| f[i] == 'u' || f[i] == 'U' || f[i] == 'x' || f[i] == 'X'\
	|| f[i] == 'c' || f[i] == 'C')
		*res += true_parsing(f, f[i], args);
	else if (f[i] == '\0')
		return (&f[i]);
	else
		*res += trash_func(f, f[i]);
	return (&f[i + 1]);
}
