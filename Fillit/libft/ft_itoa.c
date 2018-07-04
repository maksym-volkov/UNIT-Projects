/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:03:43 by mvolkov           #+#    #+#             */
/*   Updated: 2017/10/24 16:03:43 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_atoa_part_2(int i, int n, int sign)
{
	char *tab;

	tab = (char*)malloc(sizeof(char) * (i));
	if (tab == 0)
		return (NULL);
	tab[--i] = '\0';
	if (n < 0)
	{
		tab[0] = '-';
		n = n * (-1);
	}
	while (i-- - sign)
	{
		tab[i] = n % 10 + '0';
		n /= 10;
	}
	return (tab);
}

char			*ft_itoa(int n)
{
	int	i;
	int	l;
	int	sign;

	i = 0;
	sign = 0;
	l = n;
	while (l /= 10)
		i++;
	i += 2;
	if (n < 0)
	{
		i++;
		sign = 1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_atoa_part_2(i, n, sign));
}
