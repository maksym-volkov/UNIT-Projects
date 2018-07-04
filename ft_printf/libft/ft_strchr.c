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

char	*ft_strchr(const char *src, int val)
{
	size_t len;

	len = ft_strlen(src);
	if ((unsigned char)val == '\0')
	{
		return ((char*)&src[len]);
	}
	else
	{
		while (*src != '\0')
		{
			if (*src == (unsigned char)val)
				return ((char*)src);
			src++;
		}
	}
	return (NULL);
}
