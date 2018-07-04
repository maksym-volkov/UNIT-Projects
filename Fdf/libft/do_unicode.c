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

void			print_uni(wchar_t uni)
{
	if (uni <= 127)
		write(1, &uni, 1);
	else if (uni <= 2047)
	{
		ft_putchar((uni / 64) | 0xC0);
		ft_putchar((uni & 0x3F) | 0x80);
	}
	else if (uni <= 65535)
	{
		ft_putchar((uni / 4096) | 0xE0);
		ft_putchar(((uni / 64) & 0x3F) | 0x80);
		ft_putchar((uni & 0x3F) | 0x80);
	}
	else if (uni <= 2097151)
	{
		ft_putchar((uni / 262144) | 0xF0);
		ft_putchar(((uni / 4096) & 0x3F) | 0x80);
		ft_putchar(((uni / 64) & 0x3F) | 0x80);
		ft_putchar((uni & 0x3F) | 0x80);
	}
}

static	int		unicode(t_qualifiers q, wchar_t uni, int length)
{
	int tmp;

	tmp = length;
	q.width > length ? length = q.width : 1;
	if (q.width > tmp && q.flags[2] != '-')
	{
		while (q.width-- > tmp && q.flags[1] == '0')
			write(1, "0", 1);
		q.width++;
		while (q.width-- > tmp && q.flags[1] != '0')
			write(1, " ", 1);
		print_uni(uni);
	}
	else
	{
		print_uni(uni);
		while (q.width-- > tmp)
			write(1, " ", 1);
	}
	return (length);
}

void			do_unicode_c(t_qualifiers q, va_list args, int *res)
{
	wchar_t	uni;
	int		length;

	length = 1;
	uni = (wchar_t)va_arg(args, wint_t);
	if (uni <= 127)
		length = 1;
	else if (uni <= 2047)
		length = 2;
	else if (uni <= 65535)
		length = 3;
	else if (uni <= 2097151)
		length = 4;
	*res = unicode(q, uni, length);
}
