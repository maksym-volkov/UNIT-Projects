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

void	parse_fl(t_qualifiers *q, int *i, char *f)
{
	if (f[*i] == '#' || f[*i] == '0' ||\
	f[*i] == '-' || f[*i] == '+' || f[*i] == ' ')
	{
		parse_flag(f[*i], q);
		*i += 1;
	}
	if (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z')
	{
		q->length = f[*i];
		*i += 1;
		if (f[*i] == 'h')
		{
			q->length = 'H';
			*i += 1;
		}
		if (f[*i] == 'l')
		{
			q->length = 'L';
			*i += 1;
		}
	}
}

void	parse_pw(t_qualifiers *q, int *i, char *f)
{
	if (f[*i] == '.')
	{
		if (f[*i + 1] < '0' || f[*i + 1] > '9')
		{
			q->precision = 0;
			*i += 1;
		}
		else
			q->precision = ft_atoi(&f[*i += 1]);
		while (f[*i] >= '0' && f[*i] <= '9')
			*i += 1;
	}
	if (f[*i] >= '1' && f[*i] <= '9')
	{
		q->width = ft_atoi(&f[*i]);
		while (f[*i] >= '0' && f[*i] <= '9')
			*i += 1;
	}
}

void	trash_parse(t_qualifiers *q, int *i, char *f)
{
	if (f[*i] == '0' || f[*i] == '-')
	{
		trash_flag(f[*i], q);
		*i += 1;
	}
	else if (f[*i] == '.')
	{
		q->precision = ft_atoi(&f[*i += 1]);
		while (f[*i] >= '0' && f[*i] <= '9')
			*i += 1;
	}
	else if (f[*i] >= '1' && f[*i] <= '9' && f[*i - 1] != '.')
	{
		q->width = ft_atoi(&f[*i]);
		while (f[*i] >= '0' && f[*i] <= '9')
			*i += 1;
	}
	else
		*i += 1;
}
