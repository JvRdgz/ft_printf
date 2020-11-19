/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:08:57 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/14 19:38:05 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned	char	*aux;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned	char)c)
			return (&aux[i]);
		i++;
	}
	return (NULL);
}
