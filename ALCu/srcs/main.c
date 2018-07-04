/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:45:23 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 12:14:03 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

char	*g_error2 = "ERROR\n";
char	*g_error = "Error: No such file.\n";
char	*g_error3 = "Too many arguments.\n";

static void		init_game(t_base *base)
{
	ft_bzero(base, sizeof(t_base));
	base->game_mode = 0;
}

int				main(int c, char **av)
{
	t_base		base;
	int			err;

	init_game(&base);
	if (c == 1 || c == 2)
	{
		if (!(err = get_lines(&base, c, av)))
			return (write(2, g_error2, ft_strlen(g_error2)));
		if (err == 2)
			return (write(2, g_error, ft_strlen(g_error)));
		start_game(&base);
	}
	else
		write(2, g_error3, ft_strlen(g_error3));
	return (0);
}
