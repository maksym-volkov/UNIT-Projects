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

void	hex_w(t_qualifiers q, int *res, char *hex, uintmax_t num)
{
	if (q.flags[0] == '#' && q.type == 'x' && num != 0)
		write(1, "0x", 2);
	if (q.flags[0] == '#' && q.type == 'X' && num != 0)
		write(1, "0X", 2);
	while (q.precision-- > res[1])
		write(1, "0", 1);
	write(1, hex, res[1]);
	while (res[0]++ < q.width && (q.flags[1] != '0' || q.flags[2] == '-'))
		write(1, " ", 1);
	res[0]--;
	while (res[0]++ < q.width && q.flags[1] == '0')
		write(1, "0", 1);
	res[0]--;
}

void	hex_r(t_qualifiers q, int *res, char *hex, uintmax_t num)
{
	while (res[0]++ < q.width && (q.flags[1] != '0' || q.flags[2] == '-'))
		write(1, " ", 1);
	res[0]--;
	while (res[0]++ < q.width && q.precision >= res[1])
		write(1, " ", 1);
	res[0]--;
	if (q.flags[0] == '#' && q.type == 'x' && num != 0)
		write(1, "0x", 2);
	if (q.flags[0] == '#' && q.type == 'X' && num != 0)
		write(1, "0X", 2);
	while (res[0]++ < q.width && q.flags[1] == '0')
		write(1, "0", 1);
	res[0]--;
	while (q.precision-- > res[1])
		write(1, "0", 1);
	write(1, hex, res[1]);
}
