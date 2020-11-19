/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:17:44 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/11 21:43:34 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*sr;
	unsigned	char	*dest;

	sr = (unsigned		char	*)src;
	dest = (unsigned	char	*)dst;
	if (n <= 0 || dest == sr)
		return (dest);
	while (n != 0)
	{
		*dest++ = *sr++;
		n--;
	}
	return (dst);
}
