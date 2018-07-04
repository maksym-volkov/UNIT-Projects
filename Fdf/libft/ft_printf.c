/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 02:26:10 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		throught_format(const char *format, va_list args)
{
	int		res;
	char	*start;
	char	*end;

	start = (char*)format;
	res = 0;
	while ((end = ft_strchr(start, '%')) != NULL)
	{
		write(1, start, ft_strlen(start) - ft_strlen(end));
		res += ft_strlen(start) - ft_strlen(end);
		start = ++end;
		start = parse_start(start, args, &res);
	}
	write(1, start, ft_strlen(start) - ft_strlen(end));
	res += ft_strlen(start) - ft_strlen(end);
	return (res);
}

static	int		checking_args(const char *format)
{
	char *str;

	str = ft_strchr(format, '%');
	if (str == NULL)
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	else
		return (0);
}

int				ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	va_start(args, format);
	if ((res = checking_args(format)))
		return (res);
	res = throught_format(format, args);
	va_end(args);
	return (res);
}
