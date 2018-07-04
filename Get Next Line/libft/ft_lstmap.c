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

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *newlst;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	newlst = (*f)(lst);
	if (!newlst)
		return (NULL);
	ret = newlst;
	tmp = lst->next;
	while (tmp)
	{
		newlst->next = (*f)(tmp);
		newlst = newlst->next;
		if (!newlst)
			return (NULL);
		tmp = tmp->next;
	}
	return (ret);
}
