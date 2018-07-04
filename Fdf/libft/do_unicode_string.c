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

static	void	inizialize(int *a, int *b, int *c)
{
	*a = 0;
	*b = -1;
	*c = 0;
}

static	int		str_uni_len(wchar_t *str, t_qualifiers q, int *res)
{
	int length;
	int i;
	int last;

	inizialize(&length, &i, &last);
	while (str[++i])
	{
		if (str[i] <= 127 && (last = 1))
			length += 1;
		else if (str[i] <= 2047 && (last = 2))
			length += 2;
		else if (str[i] <= 65535 && (last = 3))
			length += 3;
		else if (str[i] <= 2097151 && (last = 4))
			length += 4;
		if (length > q.precision && q.precision != -1)
			break ;
	}
	if (length > q.precision && q.precision != -1)
		length = length - last;
	*res = length;
	return (i);
}

static	void	do_null(t_qualifiers q, int *res)
{
	int		len;
	int		tmp;
	char	str[6];

	ft_strcpy(str, "(null)\0");
	len = 6;
	(len > q.precision && q.precision > -1) ? len = q.precision : 1;
	tmp = q.width - len;
	*res = len;
	q.width > len ? *res = q.width : 1;
	if (q.width == 0)
		write(1, str, len);
	else if (q.flags[2] == '-' && q.width != 0)
	{
		write(1, str, len);
		c_space(tmp, q);
	}
	else if (q.flags[2] != '-' && q.width != 0)
	{
		c_space(tmp, q);
		write(1, str, len);
	}
}

static	void	print_s(t_qualifiers q, int len, int tmp, wchar_t *str)
{
	int i;

	i = 0;
	if (q.width == 0)
		while (i < len)
			print_uni(str[i++]);
	else if (q.flags[2] == '-' && q.width != 0)
	{
		while (i < len)
			print_uni(str[i++]);
		c_space(tmp, q);
	}
	else if (q.flags[2] != '-' && q.width != 0)
	{
		c_space(tmp, q);
		while (i < len)
			print_uni(str[i++]);
	}
}

void			do_unicode_s(t_qualifiers q, va_list args, int *res)
{
	wchar_t	*str;
	int		len;
	int		tmp;

	str = va_arg(args, wchar_t*);
	if (!str)
	{
		do_null(q, res);
		return ;
	}
	len = str_uni_len(str, q, res);
	tmp = q.width - *res;
	q.width > *res ? *res = q.width : 1;
	print_s(q, len, tmp, str);
}
