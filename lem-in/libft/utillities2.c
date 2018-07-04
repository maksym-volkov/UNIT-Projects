/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 04:47:22 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:39 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_big(uintmax_t num, char *res, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789ABCDEF";
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[len - 1] = str[num % 16];
		num /= 16;
		len--;
	}
}

void	print_oct(uintmax_t num, char *res, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[len - 1] = str[num % 8];
		num /= 8;
		len--;
	}
}

int		hex_length(uintmax_t num)
{
	int i;

	i = 1;
	while (num /= 16)
		i++;
	return (i);
}
