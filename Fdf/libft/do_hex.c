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

static	int		hex(t_qualifiers q, uintmax_t num)
{
	int		res[2];
	char	*hex;

	res[0] = hex_length(num);
	hex = ft_strnew(res[0]);
	if (q.type == 'x')
		print_hex(num, hex, res[0]);
	else
		print_hex_big(num, hex, res[0]);
	res[1] = res[0];
	q.precision > res[0] ? res[0] = q.precision : 1;
	q.flags[0] == '#' && num != 0 ? res[0] += 2 : 1;
	if (q.precision == 0 && num == 0)
	{
		res[1] = 0;
		res[0] = 0;
	}
	if (res[0] >= q.width || q.flags[2] == '-')
		hex_w(q, res, hex, num);
	else if (res[0] < q.width)
		hex_r(q, res, hex, num);
	ft_strdel(&hex);
	return (res[0]);
}

void			do_x_or_x(t_qualifiers q, va_list args, int *res)
{
	intmax_t ret;

	if (q.length == 'l')
		ret = va_arg(args, unsigned long int);
	else if (q.length == 'L')
		ret = va_arg(args, unsigned long long int);
	else if (q.length == 'j')
		ret = va_arg(args, uintmax_t);
	else if (q.length == 'z')
		ret = va_arg(args, size_t);
	else
		ret = va_arg(args, unsigned int);
	if (q.length == 'h')
		ret = (unsigned short)ret;
	else if (q.length == 'H')
		ret = (unsigned char)ret;
	*res = hex(q, ret);
}
