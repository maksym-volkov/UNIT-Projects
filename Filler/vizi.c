/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/includes/libft.h"
#include <locale.h>
#include <wchar.h>

void	vis_map(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'O')
			printf("%C ", L'🍷');
		else if (str[i] == 'X')
			printf("%C ", L'🍺');
		else if (str[i] == 'x')
			printf("%C ", L'🍻');
		else if (str[i] == 'o')
			printf("%C ", L'🥂');
		else if (str[i] == '.')
			printf("%C ", L'🌝');
		else
			printf("%c", str[i]);
	}
	printf("\n");
}

int		main(void)
{
	char	*line;

	setlocale(LC_ALL, "");
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] >= '0' && line[0] <= '9')
			vis_map(line);
		else
			printf("%s\n", line);
		free(line);
	}
}
