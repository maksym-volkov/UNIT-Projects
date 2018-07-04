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

static	t_link	*add_link_to_queue(t_link *queue, t_link *link)
{
	t_link	*tmp_link;

	if (!queue)
	{
		queue = link;
		return (queue);
	}
	tmp_link = queue;
	while (tmp_link->next)
		tmp_link = tmp_link->next;
	tmp_link->next = link;
	link->next = NULL;
	return (queue);
}

static	int		in_queue(t_link *link, t_room *room)
{
	t_link	*tmp_link;

	tmp_link = link;
	while (tmp_link)
	{
		if (!(ft_strcmp(tmp_link->neighbor->name, room->name)))
			return (1);
		tmp_link = tmp_link->next;
	}
	return (0);
}

static	void	queue_update(t_link **queue, t_room *room)
{
	t_link	*tmp_links;
	t_link	*link;

	tmp_links = room->links;
	while (tmp_links)
	{
		if (!(tmp_links->neighbor->visited) && \
			!(in_queue(*queue, tmp_links->neighbor)))
		{
			link = new_link();
			tmp_links->neighbor->prev = room;
			link->neighbor = tmp_links->neighbor;
			*queue = add_link_to_queue(*queue, link);
		}
		tmp_links = tmp_links->next;
	}
}

t_room			*room_with_name(t_lemin *lemin, char *name)
{
	t_room	*tmp;

	tmp = lemin->rooms;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				solution(t_lemin *lemin)
{
	t_link	*queue;
	t_room	*tmp_room;
	t_link	*tmp_link;

	queue = new_link();
	queue->name = ft_strdup(lemin->start);
	queue->neighbor = room_with_name(lemin, lemin->start);
	while (queue)
	{
		tmp_room = queue->neighbor;
		tmp_link = queue;
		queue = queue->next;
		free(tmp_link->name);
		free(tmp_link);
		if (!tmp_room->visited)
			tmp_room->visited = 1;
		if (!(ft_strcmp(tmp_room->name, lemin->end)))
		{
			free_queue(&queue);
			return (0);
		}
		queue_update(&queue, tmp_room);
	}
	return (1);
}
