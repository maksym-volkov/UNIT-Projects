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

t_data	*new_data(void)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		ft_error("Error in memory alocation!");
	data->line = NULL;
	data->next = NULL;
	return (data);
}

t_coord	*new_coord(int x, int y, char *str)
{
	t_coord	*coord;
	int		len;

	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		ft_error("Error in memory alocation!");
	coord->x = x;
	coord->y = y;
	if (!ft_isdigit(str[0]) && (str[0] == '-' && !ft_isdigit(str[1])))
		ft_error("Wrong coordinate");
	coord->z = atoi(str);
	len = digit_len(coord->z);
	coord->color = is_color(str, len);
	// printf("color = [%i]\n", coord->color);
	return (coord);
}
