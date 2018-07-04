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

void	printf_putnbr_negative(intmax_t num, int precision)
{
	if (num < -9223372036854775807)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (precision == 0 && num == 0)
		return ;
	if (num > 9)
		printf_putnbr_negative(num / 10, 1);
	ft_putchar(num % 10 + '0');
}

void	printf_putnbr_positive(uintmax_t num, int precision)
{
	if (precision == 0 && num == 0)
		return ;
	if (num > 9)
		printf_putnbr_positive(num / 10, 1);
	ft_putchar(num % 10 + '0');
}

void	print_hex(uintmax_t num, char *res, int len)
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
		res[len - 1] = str[num % 16];
		num /= 16;
		len--;
	}
}
