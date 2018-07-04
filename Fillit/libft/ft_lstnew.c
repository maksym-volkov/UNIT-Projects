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

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lstnew;

	lstnew = (t_list*)malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
		lstnew->next = NULL;
		return (lstnew);
	}
	lstnew->content = malloc(sizeof(content));
	if (lstnew->content == NULL)
		return (NULL);
	ft_memcpy(lstnew->content, content, content_size);
	lstnew->content_size = content_size;
	lstnew->next = NULL;
	return (lstnew);
}
