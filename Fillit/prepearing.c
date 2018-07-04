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

static	void	ft_to_zero(t_co *t)
{
	while (t->x[0] != 0 && t->x[1] != 0 && t->x[2] != 0 && t->x[3] != 0)
	{
		t->x[0]--;
		t->x[1]--;
		t->x[2]--;
		t->x[3]--;
	}
	while (t->y[0] != 0 && t->y[1] != 0 && t->y[2] != 0 && t->y[3] != 0)
	{
		t->y[0]--;
		t->y[1]--;
		t->y[2]--;
		t->y[3]--;
	}
}

static	void	ft_coordinates(char ***tet, int m, t_co *t)
{
	int				i;
	int				l;
	int				j;
	int				count;

	j = -1;
	while (++j < m)
	{
		l = -1;
		count = 0;
		while (++l < 4)
		{
			i = -1;
			while (++i < 5)
			{
				if (tet[j][l][i] >= 'A' && tet[j][l][i] <= 'Z')
				{
					t[j].x[count] = i;
					t[j].y[count++] = l;
				}
			}
		}
		ft_to_zero(&t[j]);
	}
	ft_creating_map(m, t);
}

static	void	ft_change_into_letters(char ***tetnew, int m)
{
	t_co	t[m];
	int		v;
	int		y;
	int		i;

	v = 0;
	while (v < m)
	{
		y = -1;
		while (++y < 4)
		{
			i = 0;
			while (i < 5)
			{
				if (tetnew[v][y][i] == '#')
					tetnew[v][y][i] = 65 + v;
				i++;
			}
		}
		v++;
	}
	ft_coordinates(tetnew, m, t);
}

void			ft_double_to_triple(char **tet, int m, int y, int i)
{
	char	***tetnew;
	int		v;
	int		old;

	v = -1;
	if (!(tetnew = (char***)malloc(sizeof(char**) * m + 1)))
		ft_error();
	while (++v < m)
	{
		if (!(tetnew[v] = (char**)malloc(sizeof(char*) * 4 + 1)))
			ft_error();
		y = -1;
		old = 0;
		while (++y < 4)
		{
			if (!(tetnew[v][y] = (char*)malloc(sizeof(char) * 4 + 1)))
				ft_error();
			i = 0;
			while (i < 5)
				tetnew[v][y][i++] = tet[v][old++];
			tetnew[v][y][i++] = '\0';
		}
		tetnew[v][y] = NULL;
	}
	ft_change_into_letters(tetnew, m);
}
