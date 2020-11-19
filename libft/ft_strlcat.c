/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:48:19 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/18 21:30:38 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (!dstsize)
		return (lensrc);
	lendst = ft_strlen(dst);
	if ((dstsize - 1) < lendst)
		return (lensrc + dstsize);
	else if (lendst < dstsize)
	{
		while (src[i] != '\0' && i < (dstsize - lendst - 1))
		{
			dst[lendst + i] = src[i];
			i++;
		}
		dst[lendst + i] = '\0';
	}
	return (lendst + lensrc);
}
