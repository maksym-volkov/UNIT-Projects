/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 04:35:44 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			c_space(int tmp, t_qualifiers q)
{
	while ((tmp-- > 0) && q.flags[1] != '0')
		write(1, " ", 1);
	tmp++;
	while ((tmp-- > 0) && q.flags[1] == '0')
		write(1, "0", 1);
}

static	char	*do_null(int *len, char *str)
{
	str = "(null)\0";
	*len = 6;
	return (str);
}

void			do_string(t_qualifiers q, va_list args, int *res)
{
	char	*str;
	int		len;
	int		tmp;

	str = va_arg(args, char*);
	len = ft_strlen(str);
	if (!str)
		str = do_null(&len, str);
	len > q.precision && q.precision > -1 ? len = q.precision : 1;
	tmp = q.width - len;
	*res = len;
	q.width > len ? *res = q.width : 1;
	if (q.width == 0)
		write(1, str, len);
	else if (q.flags[2] == '-' && q.width != 0)
	{
		write(1, str, len);
		while (tmp--)
			write(1, " ", 1);
	}
	else if (q.flags[2] != '-' && q.width != 0)
	{
		c_space(tmp, q);
		write(1, str, len);
	}
}

void			do_char(t_qualifiers q, va_list args, int *res)
{
	unsigned char	c;
	int				tmp;

	c = va_arg(args, int);
	tmp = q.width - 1;
	*res = 1;
	q.width > 1 ? *res = q.width : 1;
	if (q.width < 2)
		write(1, &c, 1);
	else if (q.flags[2] == '-' && q.width > 1)
	{
		write(1, &c, 1);
		c_space(tmp, q);
	}
	else if (q.flags[2] != '-' && q.width > 1)
	{
		c_space(tmp, q);
		write(1, &c, 1);
	}
}
