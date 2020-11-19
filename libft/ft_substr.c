/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:26:12 by jarodrig          #+#    #+#             */
/*   Updated: 2020/01/07 13:56:23 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	lens;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	if (!(subst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		j++;
		i++;
	}
	subst[j] = '\0';
	return (subst);
}
