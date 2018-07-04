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

void		debug(t_fdf *fdf)
{
	// int y;
	// int x;

	// y = -1;
	// while (++y < fdf->dataSize)
	// {
	// 	x = -1;
	// 	while (++x < fdf->mapWidth)
	// 	{
	// 		printf("%i ", fdf->map[y][x]->z);
	// 	}
	// 	printf("\n");
	// }
	// printf("%s\n", fdf->map[y]);
	// t_data *tmp;

	// tmp = fdf->data;
	// while (tmp)
	// {
	// 	ft_printf("%s\n", tmp->line);
	// 	tmp = tmp->next;
	// }
	// printf("size = %i\n", fdf->dataSize);
}

void		ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int			main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_error("Invalid number of arguments!");
	ft_bzero(&fdf, sizeof(t_fdf));
	read_data(&fdf, av[1]);
	parse_coords(&fdf);
	create_window(&fdf);
	mlx_loop(fdf.mlx);
	debug(&fdf);
	// while (1)
	// {}
	return (0);
}
