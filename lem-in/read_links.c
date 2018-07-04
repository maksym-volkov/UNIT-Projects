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

static	void	add_link_neighbor(t_lemin *lemin, char *link1, char *link2)
{
	t_link	*tmp_link;
	t_room	*tmp_room;
	t_room	*link_room;

	tmp_room = lemin->rooms;
	link_room = NULL;
	while (tmp_room != NULL)
	{
		if (!(ft_strcmp(tmp_room->name, link1)))
		{
			tmp_link = tmp_room->links;
			while (tmp_link != NULL)
			{
				if (add_link_neighbor2(&tmp_link, &link_room, lemin, link2))
					return ;
			}
			return ;
		}
		tmp_room = tmp_room->next;
	}
}

static	void	add_link(t_lemin *lemin, char *link1, char *link2)
{
	t_link	*tmp_link;
	t_room	*tmp_room;
	t_link	*link;

	link = new_link();
	link->name = ft_strdup(link2);
	tmp_room = lemin->rooms;
	while (tmp_room != NULL)
	{
		if (!(ft_strcmp(tmp_room->name, link1)))
		{
			if (tmp_room->links == NULL)
			{
				tmp_room->links = link;
				return ;
			}
			tmp_link = tmp_room->links;
			while (tmp_link->next != NULL)
				tmp_link = tmp_link->next;
			tmp_link->next = link;
			link->next = NULL;
			return ;
		}
		tmp_room = tmp_room->next;
	}
}

static	int		through_rooms(t_lemin *lemin, char *name)
{
	t_room *tmp;

	tmp = lemin->rooms;
	while (tmp != NULL)
	{
		if (!(ft_strcmp(tmp->name, name)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static	int		free_line(t_lemin *lemin, char *link1, char *link2, int i)
{
	add_data(lemin, lemin->line);
	ft_strdel(&lemin->line);
	if (i)
	{
		free(link1);
		free(link2);
	}
	get_next_line(0, &lemin->line);
	return (1);
}

void			read_links(t_lemin *lemin)
{
	char	*l1;
	char	*l2;

	while (ft_strlen(lemin->line) > 0)
	{
		if (lemin->line[0] == '#' && free_line(lemin, l1, l2, 0))
			continue ;
		if (is_valid(lemin->line, '-'))
			return ;
		l1 = ft_strsub(lemin->line, 0, how_long_before(lemin->line, '-'));
		l2 = ft_strsub(lemin->line, how_long_before(lemin->line, '-') + 1, \
		(ft_strlen(lemin->line) - (how_long_before(lemin->line, '-') + 1)));
		if (!(through_rooms(lemin, l1)))
			ft_error();
		if (!(through_rooms(lemin, l2)))
			ft_error();
		if (check_links(lemin, l1, l2) && free_line(lemin, l1, l2, 1))
			continue ;
		add_link(lemin, l1, l2);
		add_link(lemin, l2, l1);
		add_link_neighbor(lemin, l1, l2);
		add_link_neighbor(lemin, l2, l1);
		free_line(lemin, l1, l2, 1);
	}
	free(lemin->line);
}
