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

char	*ft_strncat(char *destptr, const char *srcptr, size_t num)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (destptr[i] != '\0')
		i++;
	while (l < num && srcptr[l] != '\0')
	{
		destptr[i] = srcptr[l];
		i++;
		l++;
	}
	destptr[i] = '\0';
	return (destptr);
}
