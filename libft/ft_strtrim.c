/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:05:54 by jarodrig          #+#    #+#             */
/*   Updated: 2020/01/07 13:59:12 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_start(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	num;

	i = 0;
	j = 0;
	num = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				num = 1;
			j++;
		}
		if (num == 0)
			return (i);
		j = 0;
		num = 0;
		i++;
	}
	return (i);
}

static size_t		ft_lenaux(char const *s1, char const *set, unsigned int s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	num;

	i = ft_strlen(s1) - 1;
	j = 0;
	num = 0;
	while (i > s)
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				num = 1;
			j++;
		}
		if (num == 0)
			return (i - s + 1);
		j = 0;
		num = 0;
		i--;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	size_t			len;

	if (!s1 || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = ft_start(s1, set);
	len = ft_lenaux(s1, set, start);
	str = ft_substr(s1, start, len);
	if (str == NULL)
		return (NULL);
	str[ft_strlen(str)] = '\0';
	return (str);
}
