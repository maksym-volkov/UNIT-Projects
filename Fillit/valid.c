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

static	void	ft_check_neighbors(char **tet, int m)
{
	int i;
	int j;
	int count;

	j = -1;
	while (++j < m)
	{
		i = -1;
		count = 0;
		while (++i < 20)
		{
			if (tet[j][i] == '#')
			{
				tet[j][i + 1] == '#' ? count++ : 1;
				tet[j][i - 1] == '#' ? count++ : 1;
				tet[j][i + 5] == '#' ? count++ : 1;
				tet[j][i - 5] == '#' ? count++ : 1;
			}
		}
		if (count < 6)
			ft_error();
	}
	i = 0;
	j = 0;
	ft_double_to_triple(tet, m, i, j);
}

static	void	ft_check_sharp(char *tet)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (tet[i] == '#')
		{
			if (tet[i + 1] != '#' && tet[i - 1] != '#' &&
			tet[i + 5] != '#' && tet[i - 5] != '#')
				ft_error();
		}
		i++;
	}
}

static	void	ft_true_tetri(char **tet, int m)
{
	int i;
	int l;
	int sharp;

	l = 0;
	while (l < m)
	{
		i = 0;
		sharp = 0;
		while (i < 20)
		{
			if (tet[l][i] == '#')
			{
				sharp++;
				ft_check_sharp(tet[l]);
			}
			if (tet[l][4] != '\n' || tet[l][9] != '\n' ||
			tet[l][14] != '\n' || tet[l][19] != '\n' || sharp > 4)
				ft_error();
			i++;
		}
		l++;
	}
	ft_check_neighbors(tet, m);
}

static	void	ft_enter(char *buff, int bytes)
{
	char	**tet;
	int		i;
	int		m;
	int		v;

	i = 0;
	m = 0;
	if (!(tet = (char**)malloc(sizeof(char*) * ((bytes + 1) / 21) + 1)))
		ft_error();
	while (i < bytes)
	{
		v = 0;
		if (!(tet[m] = (char*)malloc(sizeof(char) * 20 + 1)))
			ft_error();
		while (v < 20)
			tet[m][v++] = buff[i++];
		tet[m++][v] = '\0';
		i++;
	}
	tet[m] = NULL;
	ft_true_tetri(tet, m);
}

void			ft_isvalid(char *buff, int bytes)
{
	int ss;

	ss = 0;
	while (buff[ss])
	{
		if (buff[ss] != '.' && buff[ss] != '#' && buff[ss] != '\n')
			ft_error();
		if (((ss + 1) % 21 == 0) && buff[ss] != '\n')
			ft_error();
		ss++;
	}
	ft_enter(buff, bytes);
}
