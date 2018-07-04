/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:39:23 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 12:33:17 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_H
# define M_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_base
{
	int				*lines;
	int				*calc_line;
	int				size;
	int				game_mode;
}					t_base;

int					is_all_digits(char *str);
int					get_lines(t_base *base, int c, char **av);
void				start_game(t_base *base);
int					player_one_turn(t_base *base, int index);
int					player_two_turn(t_base *base, int index);
int					ai_turn_one(t_base *base, int index);
int					ai_turn_two(t_base *base, int index);
void				make_ai_strategy(t_base *base, int i);
int					is_4k_plus_one(int num);
void				print_lines(t_base *base, int i);
void				print_strategy(t_base *base);

#endif
