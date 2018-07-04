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

static	void	point_r(t_qualifiers q, int *res, int tmp, char *hex)
{
	write(1, "0x", 2);
	while (q.precision-- > tmp)
		write(1, "0", 1);
	write(1, hex, tmp);
	while ((*res)++ < q.width)
		write(1, " ", 1);
	(*res)--;
}

static	int		print_p(t_qualifiers q, int res, int tmp, char *hex)
{
	if (res >= q.width || q.flags[2] == '-')
		point_r(q, &res, tmp, hex);
	else if (res < q.width)
	{
		while (res++ < q.width && q.flags[1] != '0')
			write(1, " ", 1);
		res--;
		while (res++ < q.width && q.precision >= tmp)
			write(1, " ", 1);
		res--;
		write(1, "0x", 2);
		while (res++ < q.width && q.flags[1] == '0')
			write(1, "0", 1);
		res--;
		while (q.precision-- > tmp)
			write(1, "0", 1);
		write(1, hex, tmp);
	}
	ft_strdel(&hex);
	return (res);
}

static	int		pointer(t_qualifiers q, long long int num)
{
	int		res;
	char	*hex;
	int		tmp;

	res = hex_length(num);
	hex = ft_strnew(res);
	print_hex(num, hex, res);
	tmp = res;
	if (num == 0)
	{
		tmp = 1;
		res = 1;
		q.precision == 0 ? tmp = 0 : 1;
		q.precision == 0 ? res = 0 : 1;
	}
	q.precision > res ? res = q.precision : 1;
	res += 2;
	return (print_p(q, res, tmp, hex));
}

void			do_p(t_qualifiers q, va_list args, int *res)
{
	long long int ret;

	ret = va_arg(args, long long int);
	*res = pointer(q, ret);
}
