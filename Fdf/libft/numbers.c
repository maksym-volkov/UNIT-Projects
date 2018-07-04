/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 04:47:22 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:39 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		pos_dec(t_qualifiers q, intmax_t num)
{
	intmax_t res[3];

	res[1] = num;
	res[0] = 1;
	while (res[1] /= 10)
		res[0] += 1;
	res[1] = res[0];
	if (q.precision > res[0])
		res[0] = q.precision;
	res[2] = q.precision;
	(num < 0 || q.flags[3] == '+' || q.flags[4] == ' ') ? res[0]++ : 1;
	if (q.precision == 0 && num == 0)
	{
		res[1] = 0;
		res[0] = 0;
	}
	if (q.flags[2] == '-' || res[0] >= q.width)
		numbers_nw(q, num, res);
	else if (res[0] < q.width)
		numbers_nr(q, num, res);
	return (res[0]);
}

static	int		neg_dec(t_qualifiers q, uintmax_t num)
{
	uintmax_t res[3];

	res[1] = num;
	res[0] = 1;
	while (res[1] /= 10)
		res[0]++;
	res[1] = res[0];
	if (q.precision > (intmax_t)res[0])
		res[0] = q.precision;
	res[2] = q.precision;
	if (q.precision == 0 && num == 0)
	{
		res[1] = 0;
		res[0] = 0;
	}
	numbers_pp(q, num, res);
	return (res[0]);
}

void			do_i_or_d(t_qualifiers q, va_list args, int *res)
{
	intmax_t ret;

	if (q.length == 'l' || q.type == 'D')
		ret = va_arg(args, long int);
	else if (q.length == 'L')
		ret = va_arg(args, long long int);
	else if (q.length == 'j')
		ret = va_arg(args, intmax_t);
	else if (q.length == 'z')
		ret = va_arg(args, size_t);
	else
		ret = va_arg(args, int);
	if (q.length == 'h' && q.type != 'D')
		ret = (short)ret;
	else if (q.length == 'H' && q.type != 'D')
		ret = (char)ret;
	*res = pos_dec(q, ret);
}

void			do_u_or_u(t_qualifiers q, va_list args, int *res)
{
	uintmax_t ret;

	if (q.length == 'l' || q.type == 'U')
		ret = va_arg(args, unsigned long int);
	else if (q.length == 'L')
		ret = va_arg(args, unsigned long long int);
	else if (q.length == 'j')
		ret = va_arg(args, uintmax_t);
	else if (q.length == 'z')
		ret = va_arg(args, size_t);
	else
		ret = va_arg(args, unsigned int);
	if (q.length == 'h' && q.type != 'U')
		ret = (unsigned short)ret;
	else if (q.length == 'H' && q.type != 'U')
		ret = (unsigned char)ret;
	*res = neg_dec(q, ret);
}
