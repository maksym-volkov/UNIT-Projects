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

void			create_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "Fdf");
	get_center(fdf);
}

static	void	go_to_center(t_fdf *fdf)
{
	int	y;
	int	x;

	y = (WIN_H) / 2 - fdf->center->y;
	x = (WIN_W) / 2 - fdf->center->x;
	// move_y();
	// move_x();
}

void			get_center(t_fdf *fdf)
{
	int x;
	int y;

	if (!(fdf->center = (t_coord*)malloc(sizeof(t_coord))))
		ft_error("Error in memory alocation!");
	x = fdf->mapWidth;
	y = fdf->dataSize;
	fdf->center->x = (fdf->map[y - 1][x - 1]->x + fdf->map[0][0]->x) / 2;
	fdf->center->y = (fdf->map[y - 1][x - 1]->y + fdf->map[0][0]->y) / 2;
	go_to_center(fdf);
}
