/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/06/04 15:13:47 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				add_link_neighbor2(t_link **tmp_link, t_room **link_room, \
									t_lemin *lemin, char *link2)
{
	if (!(ft_strcmp((*tmp_link)->name, link2)))
	{
		*link_room = lemin->rooms;
		while (*link_room)
		{
			if (!(ft_strcmp((*link_room)->name, link2)))
			{
				(*tmp_link)->neighbor = *link_room;
				return (1);
			}
			*link_room = (*link_room)->next;
		}
	}
	*tmp_link = (*tmp_link)->next;
	return (0);
}

void			read_ants_num(t_lemin *lemin)
{
	int i;

	i = -1;
	if ((get_next_line(0, &lemin->line)) == -1)
		ft_error();
	add_data(lemin, lemin->line);
	if (lemin->line[0] == '#')
	{
		free(lemin->line);
		read_ants_num(lemin);
	}
	else
	{
		while (lemin->line[++i])
			if (lemin->line[i] < '0' || lemin->line[i] > '9')
				ft_error();
		if (!(lemin->ants = ft_atoi(lemin->line)))
			ft_error();
	}
}

static	void	add_room(t_lemin *lemin, t_room *room)
{
	t_room	*tmp;

	if (lemin->rooms == NULL)
	{
		lemin->rooms = room;
		return ;
	}
	tmp = lemin->rooms;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = room;
	room->next = NULL;
}

static	char	*parse_room(t_lemin *lemin, char *str)
{
	int		i;
	int		size;
	t_room	*room;

	i = 0;
	room = new_room();
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	if (i == 0)
		ft_error();
	room->name = ft_strsub(str, 0, i);
	check_room(lemin, room->name);
	if (!(size = is_digit_before(&str[i + 1], ' ')))
		ft_error();
	room->x = ft_atoi(&str[i + 1]);
	if (!(is_digit_before(&str[i + size + 2], '\0')))
		ft_error();
	room->y = ft_atoi(&str[i + size + 2]);
	check_coord(lemin, room);
	add_room(lemin, room);
	return (room->name);
}

void			read_rooms(t_lemin *lemin)
{
	char *name;
	char *tmp;

	while ((get_next_line(0, &lemin->line) > 0) \
			&& !(ft_strchr(lemin->line, '-')))
	{
		add_data(lemin, lemin->line);
		if (lemin->line[0] == 'L')
			ft_error();
		else if (!(ft_strcmp(lemin->line, "##start")) \
		|| !(ft_strcmp(lemin->line, "##end")))
		{
			tmp = ft_strdup(lemin->line);
			free(lemin->line);
			get_next_line(0, &lemin->line);
			add_data(lemin, lemin->line);
			check_comments(lemin);
			name = parse_room(lemin, lemin->line);
			check_start_end(tmp, name, lemin);
			free(tmp);
		}
		else if (lemin->line[0] != '#')
			parse_room(lemin, lemin->line);
		free(lemin->line);
	}
}
