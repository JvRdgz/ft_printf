/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:10:15 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/14 19:37:22 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned	char	*sr;
	unsigned	char	*dest;

	sr = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (sr < dest)
	{
		while (len--)
			dest[len] = sr[len];
	}
	else if (sr > dest)
		ft_memcpy(dest, sr, len);
	return (dst);
}
