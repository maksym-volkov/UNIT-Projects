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

static	size_t	ft_len(char const *s)
{
	size_t i;
	size_t l;

	i = 0;
	l = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		if (s[i] == '\0')
			return (0);
	}
	while (s[i])
	{
		i++;
		l++;
	}
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
	{
		l--;
		i--;
	}
	return (l);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*s) * (ft_len(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	l = 0;
	while (s[i])
		str[l++] = s[i++];
	while (str[l - 1] == ' ' || str[l - 1] == '\n' || str[l - 1] == '\t')
		l--;
	str[l] = '\0';
	return (str);
}
