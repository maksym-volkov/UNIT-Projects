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

void	split_lines(t_fdf *fdf)
{
	t_coord	***map;
	t_data	*data;
	char	**line;
	int		x;
	int		y;

	map = fdf->map;
	data = fdf->data;
	line = ft_strsplit(data->line, ' ');
	fdf->mapWidth = array_len(line);
	y = -1;
	while (++y < fdf->dataSize)
	{
		if (!(map[y] = (t_coord**)malloc(sizeof(t_coord*) * (fdf->mapWidth + 1))))
			ft_error("Error in memory alocation!");
		x = -1;
		while (++x < fdf->mapWidth)
			map[y][x] = new_coord(x, y, line[x]);
		free_split(line);
		if ((data = data->next))	
			line = ft_strsplit(data->line, ' ');
		if (array_len(line) != fdf->mapWidth)
			ft_error("Error in file");
	}
	map[y] = NULL;
}

void	parse_coords(t_fdf *fdf)
{
	if (!(fdf->map = (t_coord***)malloc(sizeof(t_coord**) * (fdf->dataSize + 1))))
		ft_error("Error in memory alocation!");
	split_lines(fdf);
}

static	void	findingSize(t_fdf *fdf)
{
	t_data	*data;
	int		size;

	size = 0;
	data = fdf->data;
	while (data)
	{
		size++;
		data = data->next;
	}
	if (!size)
		ft_error("No data");
	fdf->dataSize = size;
}

static	void	add_data(t_fdf *fdf, char *line)
{
	t_data	*data;
	t_data	*tmp_data;

	data = new_data();
	data->line = ft_strdup(line);
	if (!fdf->data)
	{
		fdf->data = data;
		return ;
	}
	tmp_data = fdf->data;
	while (tmp_data->next)
		tmp_data = tmp_data->next;
	tmp_data->next = data;
	data->next = NULL;
}

void			read_data(t_fdf *fdf, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || get_next_line(fd, &fdf->line) <= 0)
		ft_error("Error in reading!");
	while (ft_strlen(fdf->line) > 0)
	{
		add_data(fdf, fdf->line);
		ft_strdel(&fdf->line);
		if (get_next_line(fd, &fdf->line) < 0)
			ft_error("Error in reading!");
	}
	ft_strdel(&fdf->line);
	findingSize(fdf);
}
