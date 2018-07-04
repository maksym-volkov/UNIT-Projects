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

size_t		ft_strlcat(char *destptr, const char *srcptr, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	while (destptr[i] != '\0')
		i++;
	dest_size = i;
	i = 0;
	while (srcptr[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	src_size = i;
	i = 0;
	while (srcptr[i] != '\0' && ((dest_size + i) < (size - 1)))
	{
		destptr[dest_size + i] = srcptr[i];
		i++;
	}
	destptr[dest_size + i] = '\0';
	return (src_size + ((dest_size < size) ? dest_size : size));
}
