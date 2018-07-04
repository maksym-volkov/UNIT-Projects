/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:28:31 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/11 21:01:10 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m.h"

char	*g_tmp_file = "input.tmp";

static int		make_free(char *line)
{
	free(line);
	return (1);
}

static int		check_file(int in_file, int tmp_file)
{
	if (in_file == -1)
	{
		close(tmp_file);
		return (1);
	}
	return (0);
}

static char		*make_file(t_base *base, int file, int in_f)
{
	char	*line;

	if (check_file(in_f, file))
		return ("errFile");
	while (get_next_line(in_f, &line) > 0)
	{
		if ((!ft_strcmp(line, "") && in_f == 0) && make_free(line))
			break ;
		if ((is_all_digits(line) || (ft_atoi(line) < 1 ||
		ft_atoi(line) > 10000) || ft_strlen(line) > 5) && make_free(line))
			return (NULL);
		write(file, line, ft_strlen(line));
		write(file, " ", 1);
		free(line);
		base->size++;
	}
	if (!base->size)
		return (NULL);
	else if (in_f)
		close(in_f);
	close(file);
	return (g_tmp_file);
}

static void		get_matches(t_base *base, int i)
{
	char	*line;
	int		file;
	char	**split;

	file = open(g_tmp_file, O_RDONLY);
	get_next_line(file, &line);
	split = ft_strsplit(line, ' ');
	free(line);
	close(file);
	while (++i < base->size)
	{
		base->lines[i] = ft_atoi(split[i]);
		free(split[i]);
	}
	free(split);
}

int				get_lines(t_base *base, int c, char **av)
{
	char		*input;

	if (c == 1)
		ft_printf("\x1B[32m" "Enter matches on the board:\n" "\x1B[31m");
	input = make_file(base,
		open(g_tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644),
		c == 1 ? 0 : open(av[1], O_RDONLY));
	if (!input)
		return (0);
	if (!ft_strcmp(input, "errFile"))
		return (2);
	base->lines = (int*)malloc(sizeof(int) * base->size);
	base->calc_line = (int*)malloc(sizeof(int) * base->size);
	ft_bzero(base->calc_line, base->size * sizeof(int));
	get_matches(base, -1);
	make_ai_strategy(base, -1);
	return (1);
}
