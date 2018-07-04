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

#include "lemin.h"

static	void	add_step(t_path **path, t_path *new_step)
{
	if (*path)
		(*path)->prev = new_step;
	else
		new_step->end = 1;
	new_step->next = *path;
	*path = new_step;
}

void			find_path(t_lemin *lemin)
{
	t_room	*tmp_room;
	t_path	*path;
	t_path	*new_step;

	tmp_room = room_with_name(lemin, lemin->end);
	path = lemin->path;
	while (tmp_room)
	{
		new_step = new_path();
		new_step->room = tmp_room;
		add_step(&path, new_step);
		lemin->path = path;
		if (!(ft_strcmp(tmp_room->name, lemin->start)))
			break ;
		tmp_room = tmp_room->prev;
	}
	lemin->path->start = 1;
}

void			print_path(t_lemin *lemin, int ants_arriv, \
							int tmp_ants, int curr_ant)
{
	t_path	*path;

	path = lemin->path->next;
	while (path && (curr_ant = lemin->ants - (lemin->ants - ants_arriv) + 1))
	{
		while (path->busy && !path->end)
			path = path->next;
		while (path && path->prev)
		{
			if (!print_start(path, &tmp_ants, ants_arriv, curr_ant))
				break ;
			if (path->prev->busy && !path->end)
				prev_path(&curr_ant, path, ants_arriv);
			else if (path->end && end_path(path, &curr_ant, &ants_arriv))
			{
				if (ants_arriv == lemin->ants)
					return ;
			}
			else
				break ;
			path = path->prev;
		}
		write(1, "\n", 1);
		path = path->next;
	}
}

int				check_links(t_lemin *lemin, char *link1, char *link2)
{
	t_room	*room;
	t_link	*link;

	room = lemin->rooms;
	while (room)
	{
		if (!(ft_strcmp(room->name, link1)))
		{
			link = room->links;
			while (link)
			{
				if (!(ft_strcmp(link->name, link2)))
					return (1);
				link = link->next;
			}
		}
		room = room->next;
	}
	return (0);
}

void			check_comments(t_lemin *lemin)
{
	while (lemin->line[0] == '#')
	{
		free(lemin->line);
		get_next_line(0, &lemin->line);
		add_data(lemin, lemin->line);
	}
	if (lemin->line[0] == 'L')
			ft_error();
}
