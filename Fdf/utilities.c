/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		digit_len(int num)
{
	int i;

	i = 1;
	if (num < 0)
		i++;
	while (num /= 10)
		i++;
	return (i);
}

int		array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int		is_color(char *str, int len)
{
	int i;

	if (!str[len])
		return (16777215);
	if (ft_strncmp(&str[len], ",0x", 3))
		ft_error("Wrong coordinate");
	if (ft_strlen(&str[len + 3]) != 6)
		ft_error("Wrong coordinate");
	i = len + 2;
	while (str[++i])
		if (!ft_isdigit(str[i]) && (str[i] > 'f'\
		 || (str[i] < 'a' && str[i] > 'F') || str[i] < 'A'))
			ft_error("Wrong coordinate");
	return (ft_atoi_base(&str[len + 3], 16));
}

