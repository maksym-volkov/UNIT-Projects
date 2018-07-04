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

static	char	*split2(const char *s, int i, const char c)
{
	int		k;
	char	*str;

	i--;
	k = 0;
	k = i;
	while (s[k] != c && k != -1)
		k--;
	str = (char*)malloc(sizeof(*s) * (i - k + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != c && i != -1)
		i--;
	i++;
	k = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

static	size_t	ft_len(const char *str, char const c)
{
	size_t i;
	size_t l;

	i = 0;
	l = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		l++;
	}
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (s == NULL)
		return (NULL);
	str = (char**)malloc(sizeof(*str) * (ft_len(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && s[i - 1] == c)
			break ;
		str[j] = split2(s, i, c);
		j++;
	}
	str[j] = 0;
	return (str);
}
