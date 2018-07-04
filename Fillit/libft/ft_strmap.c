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

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*snew;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	snew = (char*)malloc(sizeof(*s) * (i + 1));
	if (!snew)
		return (NULL);
	i = 0;
	while (s[i])
	{
		snew[i] = f(s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
