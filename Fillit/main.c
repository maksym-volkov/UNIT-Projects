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

int		ft_usage(void)
{
	ft_putstr("usage: fillit target_file\n");
	exit(1);
}

int		ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buff[1];

	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, 0) < 0)
		ft_error();
	ft_read_fd(fd);
	close(fd);
	return (0);
}
