/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:34:13 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 05:37:56 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct			s_path
{
	struct s_room		*room;
	struct s_path		*next;
	struct s_path		*prev;
	int					start;
	int					end;
	int					busy;
}						t_path;

typedef struct			s_data
{
	struct s_data		*next;
	char				*line;
}						t_data;

typedef struct			s_link
{
	char				*name;
	struct s_room		*neighbor;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	int					x;
	int					y;
	int					visited;
	char				*name;
	struct s_room		*next;
	struct s_room		*prev;
	struct s_link		*links;
}						t_room;

typedef struct			s_lemin
{
	char				*line;
	int					ants;
	char				*start;
	char				*end;
	t_room				*rooms;
	t_path				*path;
	t_data				*data;
}						t_lemin;

/*
**						find_path.c
*/

void					find_path(t_lemin *lemin);
void					print_path(t_lemin *lemin, int ants_arriv, \
									int tmp_ants, int curr_ant);
int						check_links(t_lemin *lemin, char *link1, char *link2);
void					check_comments(t_lemin *lemin);

/*
**						free_lemin.c
*/

void					free_lemin(t_lemin *lemin);
void					free_queue(t_link **queue);
void					check_coord(t_lemin *lemin, t_room *room);
void					check_start_end(char *tmp, char *name, t_lemin *lemin);

/*
**						inizializing.c
*/

void					init_lem(t_lemin *lemin);
t_room					*new_room(void);
t_link					*new_link(void);
t_path					*new_path(void);
t_data					*new_data(void);

/*
**						main.c
*/

void					ft_error(void);

/*
**						print_map.c
*/

void					print_map(t_lemin *lemin);
int						print_start(t_path *path, int *tmp_ants, \
									int ants_arriv, int curr_ant);
int						end_path(t_path *path, int *curr_ant, int *ants_arriv);
void					prev_path(int *curr_ant, t_path *path, int ants_arriv);

/*
**						read_input.c
*/

void					read_rooms(t_lemin *lemin);
void					read_ants_num(t_lemin *lemin);
int						add_link_neighbor2(t_link **tmp_link, \
				t_room **link_room, t_lemin *lemin, char *link2);

/*
**						read_links.c
*/

void					read_links(t_lemin *lemin);

/*
**						solution.c
*/

int						solution(t_lemin *lemin);
t_room					*room_with_name(t_lemin *lemin, char *name);

/*
**						utilities.c
*/

int						is_digit_before(char *str, char c);
int						how_long_before(char *str, char c);
int						is_valid(char *str, char c);
void					add_data(t_lemin *lemin, char *line);
void					check_room(t_lemin *lemin, char *name);

#endif
