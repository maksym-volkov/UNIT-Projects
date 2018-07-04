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

void	numbers_nw(t_qualifiers q, intmax_t num, intmax_t *res)
{
	if (q.flags[3] == '+' && num > -1)
		write(1, "+", 1);
	else if (q.flags[3] != '+' && q.flags[4] == ' ' && num > -1)
		write(1, " ", 1);
	if (num < 0)
		write(1, "-", 1);
	while (q.precision-- > res[1])
		write(1, "0", 1);
	num < 0 ? printf_putnbr_negative(num * \
	-1, res[2]) : printf_putnbr_negative(num, res[2]);
	while (res[0]++ < q.width)
		write(1, " ", 1);
	res[0] -= 1;
}

void	numbers_nr(t_qualifiers q, intmax_t num, intmax_t *res)
{
	while (res[0]++ < q.width && q.flags[1] != '0')
		write(1, " ", 1);
	res[0]--;
	while (res[0]++ < q.width && q.precision >= res[1])
		write(1, " ", 1);
	res[0]--;
	if (q.flags[3] != '+' && q.flags[4] == ' ' && num > -1)
		write(1, " ", 1);
	if (q.flags[3] == '+' && num > -1)
		write(1, "+", 1);
	if (num < 0)
		write(1, "-", 1);
	while (q.precision-- > res[1])
		write(1, "0", 1);
	while (res[0]++ < q.width && q.flags[1] == '0')
		write(1, "0", 1);
	res[0] -= 1;
	num < 0 ? printf_putnbr_negative(num * \
	-1, res[2]) : printf_putnbr_negative(num, res[2]);
}

void	numbers_pp(t_qualifiers q, uintmax_t num, uintmax_t *res)
{
	if (q.flags[2] == '-' || (intmax_t)res[0] >= q.width)
	{
		while (q.precision-- > (int)res[1])
			write(1, "0", 1);
		printf_putnbr_positive(num, res[2]);
		while ((intmax_t)res[0]++ < q.width)
			write(1, " ", 1);
		res[0] -= 1;
	}
	else if ((intmax_t)res[0] < q.width)
	{
		while ((intmax_t)res[0]++ < q.width && q.flags[1] != '0')
			write(1, " ", 1);
		res[0] -= 1;
		while (q.precision-- > (int)res[1] && q.flags[1] == '0')
			write(1, " ", 1);
		q.precision++;
		while (q.precision-- > (int)res[1] && q.flags[1] != '0')
			write(1, "0", 1);
		while ((intmax_t)res[0]++ < q.width && q.flags[1] == '0')
			write(1, "0", 1);
		res[0] -= 1;
		printf_putnbr_positive(num, res[2]);
	}
}
