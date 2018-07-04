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

static	int		ft_finding_place(char **map, int mtmp, t_map *c, t_co *t)
{
	int i;
	int size;
	int xnew;
	int ynew;

	size = ft_strlen(map[1]);
	i = 0;
	ynew = -1;
	while (++ynew < size)
	{
		xnew = 0;
		while (xnew < size)
		{
			if (c->y + t[mtmp].y[i] == ynew && c->x + t[mtmp].x[i] == xnew &&
				map[c->y + t[mtmp].y[i]][c->x + t[mtmp].x[i]] != '.')
				return (0);
			else if (c->y + t[mtmp].y[i] == ynew && c->x + t[mtmp].x[i] == xnew
			&& map[c->y + t[mtmp].y[i]][c->x + t[mtmp].x[i]] == '.')
				i++;
			xnew++;
		}
	}
	if (i != 4)
		return (0);
	return (1);
}

static	void	ft_write_map(char **map, int mtmp, t_map *c, t_co *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[c->y + t[mtmp].y[i]][c->x + t[mtmp].x[i]] = mtmp + 65;
		i++;
	}
}

static	void	ft_clear(char **map, int sizemap, int mtmp)
{
	int x;
	int y;

	y = 0;
	while (y < sizemap - 1)
	{
		x = 0;
		while (x < sizemap - 1)
		{
			if (map[y][x] == mtmp + 65)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

static	char	**ft_solution(char **map, int m, int mtmp, t_co *t)
{
	t_map	c;
	char	**mapnew;
	int		sizemap;

	sizemap = (ft_strlen(map[0]) + 1);
	if (mtmp == m)
		return (map);
	c.y = -1;
	mapnew = NULL;
	while (++c.y < sizemap)
	{
		c.x = -1;
		while (++c.x < sizemap)
		{
			if (ft_finding_place(map, mtmp, &c, t))
			{
				ft_write_map(map, mtmp, &c, t);
				mapnew = ft_solution(map, m, mtmp + 1, t);
			}
			if (mapnew)
				return (mapnew);
			ft_clear(map, sizemap, mtmp);
		}
	}
	return (NULL);
}

void			ft_creating_map(int m, t_co *t)
{
	char	**map;
	int		i;
	int		sizemap;
	int		mtmp;

	i = 0;
	sizemap = 3;
	mtmp = 0;
	map = (char**)malloc(sizeof(char*) * sizemap);
	while (i < 2)
	{
		map[i] = (char*)malloc(sizeof(char) * sizemap);
		map[i] = ft_memset(map[i], '.', 2);
		map[i++][2] = '\0';
	}
	map[i] = NULL;
	while ((ft_solution(map, m, mtmp, t) == NULL))
	{
		sizemap++;
		map = ft_map_bigger(map, sizemap);
	}
	ft_print_map(map);
}
