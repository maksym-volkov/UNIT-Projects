/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_biger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakovet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:26:49 by ymakovet          #+#    #+#             */
/*   Updated: 2017/11/28 14:26:50 by ymakovet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map_bigger(char **map, int sizemap)
{
	int i;

	i = 0;
	while (i < sizemap - 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = (char**)malloc(sizeof(char*) * sizemap);
	i = 0;
	while (i < sizemap - 1)
	{
		map[i] = (char*)malloc(sizeof(char) * sizemap);
		map[i] = ft_memset(map[i], '.', sizemap - 1);
		map[i++][sizemap - 1] = '\0';
	}
	map[i] = NULL;
	return (map);
}
