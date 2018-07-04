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

void	print_map(t_lemin *lemin)
{
	t_data	*data;

	data = lemin->data;
	while (data)
	{
		ft_printf("%s\n", data->line);
		data = data->next;
	}
}

void	prev_path(int *curr_ant, t_path *path, int ants_arriv)
{
	if (path->next && (path->next->busy || (path->next->end && ants_arriv)))
		write(1, " ", 1);
	ft_printf("L%i-%s", *curr_ant, path->room->name);
	path->busy = 1;
	path->prev->busy = 0;
	*curr_ant += 1;
}

int		end_path(t_path *path, int *curr_ant, int *ants_arriv)
{
	ft_printf("L%i-%s", *curr_ant, path->room->name);
	path->prev->busy = 0;
	*curr_ant += 1;
	*ants_arriv += 1;
	return (1);
}

int		print_start(t_path *path, int *tmp_ants, int ants_arriv, int curr_ant)
{
	if (path->prev->start && *tmp_ants && !path->end)
	{
		if (path->next && (path->next->busy || (path->next->end && ants_arriv)))
			write(1, " ", 1);
		ft_printf("L%i-%s", curr_ant, path->room->name);
		*tmp_ants -= 1;
		path->busy = 1;
		return (0);
	}
	else if (path->prev->start && !path->end)
		return (0);
	return (1);
}
