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

t_room	*new_room(void)
{
	t_room *room;

	if (!(room = malloc(sizeof(t_room))))
		ft_error();
	room->x = 0;
	room->y = 0;
	room->name = NULL;
	room->next = NULL;
	room->links = NULL;
	room->prev = NULL;
	room->visited = 0;
	return (room);
}

void	init_lem(t_lemin *lemin)
{
	lemin->line = NULL;
	lemin->ants = 0;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->rooms = NULL;
	lemin->path = NULL;
	lemin->data = NULL;
}

t_link	*new_link(void)
{
	t_link *link;

	if (!(link = malloc(sizeof(t_link))))
		ft_error();
	link->name = NULL;
	link->next = NULL;
	link->neighbor = NULL;
	return (link);
}

t_data	*new_data(void)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		ft_error();
	data->line = NULL;
	data->next = NULL;
	return (data);
}

t_path	*new_path(void)
{
	t_path *path;

	if (!(path = malloc(sizeof(t_path))))
		ft_error();
	path->next = NULL;
	path->room = NULL;
	path->prev = NULL;
	path->busy = 0;
	path->start = 0;
	path->end = 0;
	return (path);
}
