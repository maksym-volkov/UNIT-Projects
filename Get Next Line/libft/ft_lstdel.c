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

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *newlst;
	t_list *nextlst;

	if (del == NULL || alst == NULL || *alst == NULL)
		return ;
	newlst = *alst;
	while (newlst)
	{
		nextlst = newlst->next;
		del((newlst->content), newlst->content_size);
		free(newlst);
		newlst = nextlst;
	}
	*alst = NULL;
}
