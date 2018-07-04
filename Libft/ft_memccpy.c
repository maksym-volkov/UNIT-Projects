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

void	*ft_memccpy(void *dst, const void *source, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;
	unsigned char	k;

	i = 0;
	k = c;
	if (dst == source)
		return (dst);
	src = (unsigned char *)source;
	dest = (unsigned char *)dst;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == k)
		{
			i++;
			return (&dst[i]);
		}
		i++;
	}
	return (NULL);
}
