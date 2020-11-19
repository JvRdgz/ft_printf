/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:14:51 by jarodrig          #+#    #+#             */
/*   Updated: 2020/01/05 17:14:57 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	if (!lst)
		return (0);
	size = 1;
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}
