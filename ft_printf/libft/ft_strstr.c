/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:03:43 by mvolkov           #+#    #+#             */
/*   Updated: 2017/10/24 16:03:43 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, const char *to_find)
{
	int i;
	int l;

	i = 0;
	l = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[l] != '\0')
	{
		i = 0;
		while (str[l + i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
				return (str + l);
			i++;
		}
		l++;
	}
	return (NULL);
}
