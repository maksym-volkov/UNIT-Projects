/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:34:13 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 05:37:56 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char str)
{
	if (str >= '0' && str <= '9')
		return (str - 48);
	if (str >= 'a' && str <= 'f')
		return (str - 97 + 10);
	if (str >= 'A' && str <= 'F')
		return (str - 65 + 10);
	return (0);
}

long int		ft_atoi_base(char *str, int base)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 0;
	res = 0;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		sign = 1;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
		res = res * base + (check(str[i++]));
	return (sign ? -(int)res : (int)res);
}
