/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:34:13 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 05:37:56 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

# define BUFF_SIZE 8

typedef struct	s_qualifiers
{
	char		flags[5];
	int			width;
	int			precision;
	char		length;
	char		type;
}				t_qualifiers;

int				ft_printf(const char *format, ...);
char			*parse_start(char *f, va_list args, int *res);
void			do_string(t_qualifiers q, va_list args, int *res);
void			do_char(t_qualifiers q, va_list args, int *res);
void			do_i_or_d(t_qualifiers q, va_list args, int *res);
void			do_u_or_u(t_qualifiers q, va_list args, int *res);
void			do_x_or_x(t_qualifiers q, va_list args, int *res);
void			do_o_or_o(t_qualifiers q, va_list args, int *res);
void			do_p(t_qualifiers q, va_list args, int *res);
void			do_unicode_c(t_qualifiers q, va_list args, int *res);
void			do_unicode_s(t_qualifiers q, va_list args, int *res);
int				trash_func(char *f, unsigned char end);
void			trash_flag(char flag, t_qualifiers *q);
void			printf_putnbr_negative(intmax_t num, int precision);
void			printf_putnbr_positive(uintmax_t num, int precision);
void			print_hex(uintmax_t num, char *res, int len);
void			print_hex_big(uintmax_t num, char *res, int len);
void			print_oct(uintmax_t num, char *res, int len);
void			print_uni(wchar_t uni);
int				hex_length(uintmax_t num);
void			c_space(int tmp, t_qualifiers q);
void			parse_fl(t_qualifiers *q, int *i, char *f);
void			parse_flag(char flag, t_qualifiers *q);
void			parse_pw(t_qualifiers *q, int *i, char *f);
void			trash_parse(t_qualifiers *q, int *i, char *f);
void			numbers_nr(t_qualifiers q, intmax_t num, intmax_t *res);
void			numbers_nw(t_qualifiers q, intmax_t num, intmax_t *res);
void			numbers_pp(t_qualifiers q, uintmax_t num, uintmax_t *res);
void			octal_null(t_qualifiers q, uintmax_t num, int *tmp, int *res);
void			octal_w(t_qualifiers q, int tmp, int *res, char *oct);
void			octal_r(t_qualifiers q, int tmp, int *res, char *oct);
void			hex_w(t_qualifiers q, int *res, char *hex, uintmax_t num);
void			hex_r(t_qualifiers q, int *res, char *hex, uintmax_t num);
void			iniz(t_qualifiers *q);

#endif
