/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:13:59 by jarodrig          #+#    #+#             */
/*   Updated: 2020/01/05 17:14:14 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list *newlst;
	t_list *rlst;

	if (!l || !f)
		return (NULL);
	if (!(newlst = ft_lstnew((*f)(l->content))))
		return (NULL);
	rlst = newlst;
	l = l->next;
	while (l)
	{
		if (!(newlst->next = ft_lstnew((*f)(l->content))))
		{
			ft_lstclear(&rlst, d);
			return (NULL);
		}
		newlst = newlst->next;
		l = l->next;
	}
	newlst->next = NULL;
	return (rlst);
}
