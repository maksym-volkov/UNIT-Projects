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

void		ft_error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

int			main(void)
{
	t_lemin		lemin;
	int			ants_arrived;
	int			tmp_ants;
	int			curr_ant;

	ants_arrived = 0;
	curr_ant = 0;
	init_lem(&lemin);
	read_ants_num(&lemin);
	free(lemin.line);
	read_rooms(&lemin);
	if (!lemin.start || !lemin.end)
		ft_error();
	read_links(&lemin);
	if (solution(&lemin))
		ft_error();
	find_path(&lemin);
	print_map(&lemin);
	tmp_ants = lemin.ants;
	ft_printf("\n");
	print_path(&lemin, ants_arrived, tmp_ants, curr_ant);
	ft_printf("\n");
	free_lemin(&lemin);
	return (0);
}
