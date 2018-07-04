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

void	octal_null(t_qualifiers q, uintmax_t num, int *tmp, int *res)
{
	q.flags[0] == '#' ? *res += 1 : 1;
	*tmp = *res;
	q.precision > *res ? *res = q.precision : 1;
	if (num == 0)
	{
		*tmp = 1;
		*res = 1;
	}
	if (num == 0 && q.precision == 0)
	{
		*tmp = 0;
		*res = 0;
		q.flags[0] == '#' ? *res = 1 : 1;
		q.flags[0] == '#' ? *tmp = 1 : 1;
	}
}

void	octal_w(t_qualifiers q, int tmp, int *res, char *oct)
{
	if (q.flags[0] == '#' && oct[0] != '0')
		write(1, "0", 1);
	while (q.precision-- > tmp)
		write(1, "0", 1);
	(q.flags[0] == '#' && oct[0] != '0') ? tmp -= 1 : 1;
	write(1, oct, tmp);
	while ((*res)++ < q.width && (q.flags[1] != '0' || q.flags[2] == '-'))
		write(1, " ", 1);
	*res -= 1;
	while ((*res)++ < q.width && q.flags[1] == '0')
		write(1, "0", 1);
	*res -= 1;
}

void	octal_r(t_qualifiers q, int tmp, int *res, char *oct)
{
	while ((*res)++ < q.width && (q.flags[1] != '0' || q.flags[2] == '-'))
		write(1, " ", 1);
	*res -= 1;
	while ((*res)++ < q.width && q.precision >= tmp)
		write(1, " ", 1);
	*res -= 1;
	if (q.flags[0] == '#' && oct[0] != '0')
		write(1, "0", 1);
	while ((*res)++ < q.width && q.flags[1] == '0')
		write(1, "0", 1);
	*res -= 1;
	while (q.precision-- > tmp)
		write(1, "0", 1);
	q.flags[0] == '#' ? tmp -= 1 : 1;
	write(1, oct, tmp);
}
