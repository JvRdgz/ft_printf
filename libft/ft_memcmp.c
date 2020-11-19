/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:43:31 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/14 20:43:53 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*c1;
	unsigned	char	*c2;
	size_t				i;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (c1 == c2)
		return (0);
	while (i < n)
	{
		if ((int)c1[i] - (int)c2[i] != 0)
			return ((int)c1[i] - (int)c2[i]);
		i++;
	}
	return (0);
}
