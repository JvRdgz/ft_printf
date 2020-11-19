/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:57:15 by jarodrig          #+#    #+#             */
/*   Updated: 2019/11/18 20:21:04 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned	char	*sr1;
	unsigned	char	*sr2;

	sr1 = (unsigned	char *)s1;
	sr2 = (unsigned	char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && sr1[i] != '\0' && sr2[i] != '\0' && sr1[i] == sr2[i])
		i++;
	return (sr1[i] - sr2[i]);
}
