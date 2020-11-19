/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_own_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:15:15 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/11 19:15:18 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse_str(const char *str)
{
	int					i;
	int					j;
	char				*reverse;

	i = 0;
	j = ft_strlen(str) - 1;
	reverse = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (str)
	{
		while (str[i] != '\0')
		{
			reverse[i] = str[j];
			i++;
			j--;
		}
	}
	reverse[i] = '\0';
	return (reverse);
}

char	*ft_reverse_str_itoa(char *str)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	if (!(aux = malloc(ft_strlen(str) + 1 * sizeof(char))))
		return (NULL);
	if (str[i] == '-')
	{
		aux[i] = '-';
		i++;
	}
	while (str[i] != '\0')
	{
		aux[i] = str[j];
		i++;
		j--;
	}
	aux[i] = '\0';
	str = ft_memcpy(str, aux, ft_strlen(aux));
	free(aux);
	return (str);
}

char	*ft_concat_strs(char *init, const char *final)
{
	int					j;
	int					i;
	char				*result;
	int					total_len;

	i = 0;
	j = 0;
	total_len = ft_strlen(init) + ft_strlen(final) + 1;
	result = ft_calloc(total_len, sizeof(char));
	while (init[i] != '\0')
	{
		result[i] = init[i];
		i++;
	}
	while (final[j] != '\0')
	{
		result[i] = final[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_put_unsigned_nbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_put_unsigned_nbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}
