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

void			free_queue(t_link **queue)
{
	t_link	*tmp;

	while (*queue)
	{
		free((*queue)->name);
		tmp = *queue;
		*queue = (*queue)->next;
		free(tmp);
	}
}

static	void	free_rooms(t_lemin *lemin)
{
	t_room	*room;
	t_room	*tmp_room;
	t_link	*link;
	t_link	*tmp_link;

	room = lemin->rooms;
	while (room)
	{
		link = room->links;
		while (link)
		{
			free(link->name);
			tmp_link = link;
			link = link->next;
			free(tmp_link);
		}
		free(room->name);
		tmp_room = room;
		room = room->next;
		free(tmp_room);
	}
}

void			free_lemin(t_lemin *lemin)
{
	t_path	*path;
	t_path	*tmp;

	free_rooms(lemin);
	path = lemin->path;
	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp);
	}
}

void			check_start_end(char *tmp, char *name, t_lemin *lemin)
{
	if (!(ft_strcmp(&tmp[2], "start")))
	{
		if (lemin->start)
			ft_error();
		lemin->start = ft_strdup(name);
	}
	if (!(ft_strcmp(&tmp[2], "end")))
	{
		if (lemin->end)
			ft_error();
		lemin->end = ft_strdup(name);
	}
}

void			check_coord(t_lemin *lemin, t_room *room)
{
	t_room	*tmp_room;

	tmp_room = lemin->rooms;
	while (tmp_room)
	{
		if (tmp_room->x == room->x && tmp_room->y == room->y)
			ft_error();
		tmp_room = tmp_room->next;
	}
}
