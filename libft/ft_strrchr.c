/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:58:05 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/18 19:52:41 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sr;
	size_t	len;

	sr = (char *)s;
	len = ft_strlen(sr);
	len += 1;
	while (len--)
	{
		if (sr[len] == (char)c)
			return (&sr[len]);
	}
	return (NULL);
}
