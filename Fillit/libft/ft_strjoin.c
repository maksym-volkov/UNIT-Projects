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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	l = 0;
	while (s1[i])
		i++;
	while (s2[l])
		l++;
	str = (char*)malloc(sizeof(*s1) * (i + l + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	l = 0;
	while (s2[l])
		str[i++] = s2[l++];
	str[i] = '\0';
	return (str);
}
