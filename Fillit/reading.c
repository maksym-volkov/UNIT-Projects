/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:00:18 by mvolkov           #+#    #+#             */
/*   Updated: 2017/11/15 14:00:18 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int m;

	m = 0;
	while (map[m])
	{
		ft_putstr(map[m]);
		ft_putchar('\n');
		m++;
	}
}

void	ft_read_fd(int fd)
{
	int		bytes;
	char	buff[546];

	bytes = read(fd, buff, 546);
	if (bytes > 545 || ((bytes + 1) % 21 != 0) || bytes < 1)
		ft_error();
	buff[bytes] = '\0';
	ft_isvalid(buff, bytes);
}
