/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:00:18 by mvolkov           #+#    #+#             */
/*   Updated: 2017/11/15 14:00:18 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_co
{
	int x[4];
	int y[4];

}				t_co;

typedef	struct	s_map
{
	int x;
	int y;

}				t_map;

int				main(int ac, char **av);
void			ft_read_fd(int fd);
void			ft_isvalid(char *buff, int bytes);
int				ft_error(void);
void			ft_double_to_triple(char **tet, int m, int y, int i);
void			ft_creating_map(int m, t_co *t);
char			**ft_map_bigger(char **map, int sizemap);
void			ft_print_map(char **map);

#endif
