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

int		is_digit_before(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (i);
}

int		is_valid(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == c)
			count++;
		if ((str[i] == c && (i == 0 || str[i + 1] == '\0')) \
			|| str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int		how_long_before(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	check_room(t_lemin *lemin, char *name)
{
	t_room	*tmp;

	tmp = lemin->rooms;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name)))
			ft_error();
		tmp = tmp->next;
	}
}

void	add_data(t_lemin *lemin, char *line)
{
	t_data	*data;
	t_data	*tmp_data;

	data = new_data();
	data->line = ft_strdup(line);
	if (!lemin->data)
	{
		lemin->data = data;
		return ;
	}
	tmp_data = lemin->data;
	while (tmp_data->next)
		tmp_data = tmp_data->next;
	tmp_data->next = data;
	data->next = NULL;
}
