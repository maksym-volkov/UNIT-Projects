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

static int		oct_length(uintmax_t num)
{
	int i;

	i = 1;
	while (num /= 8)
		i++;
	return (i);
}

static	int		octal(t_qualifiers q, uintmax_t num)
{
	int		res;
	char	*oct;
	int		tmp;

	res = oct_length(num);
	oct = ft_strnew(res);
	print_oct(num, oct, res);
	octal_null(q, num, &tmp, &res);
	if (res >= q.width || q.flags[2] == '-')
		octal_w(q, tmp, &res, oct);
	else if (res < q.width)
		octal_r(q, tmp, &res, oct);
	ft_strdel(&oct);
	return (res);
}

void			do_o_or_o(t_qualifiers q, va_list args, int *res)
{
	uintmax_t ret;

	if (q.length == 'l' || q.type == 'O')
		ret = va_arg(args, unsigned long int);
	else if (q.length == 'L')
		ret = va_arg(args, unsigned long long int);
	else if (q.length == 'j')
		ret = va_arg(args, uintmax_t);
	else if (q.length == 'z')
		ret = va_arg(args, size_t);
	else
		ret = va_arg(args, unsigned int);
	if (q.length == 'h' && q.type != 'O')
		ret = (unsigned short)ret;
	else if (q.length == 'H' && q.type != 'O')
		ret = (unsigned char)ret;
	*res = octal(q, ret);
}
