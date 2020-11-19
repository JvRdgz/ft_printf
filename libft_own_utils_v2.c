/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_own_utils_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:58 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 17:54:35 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strange_case(const char *format, t_struct *ft_struct)
{
	int		j;

	j = 0;
	if (ft_strchr("*#+ -", format[ft_struct->i]))
	{
		j = ft_struct->i;
		j++;
		if (format[ft_struct->i] == '*')
		{
			ft_struct->precision_is_valid = 0;
			ft_struct->is_precision = 1;
			if (!(ft_strchr("cspdiuxX", format[j])))
				ft_struct->len += write(1, &format[j], 1);
		}
		else if (format[ft_struct->i] == '-' && ft_isdigit(format[j]) == 1)
			ft_calculate_width(format, ft_struct);
		else if (!(ft_strchr("cspdiuxX", format[j])))
			ft_struct->len += write(1, &format[j], 1);
	}
	else if (!(ft_strchr("*#+- ", format[ft_struct->i])))
		ft_struct->len += write(1, &format[ft_struct->i], 1);
}

char	*ft_itoa(int n)
{
	long	int					nb;
	int							i;
	char						aux[12];
	char						*raux;
	char						*str;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		aux[i++] = '-';
		nb *= -1;
	}
	if (nb == 0)
		aux[i++] = '0';
	while (nb > 0)
	{
		aux[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	aux[i] = '\0';
	raux = ft_reverse_str_itoa(aux);
	str = ft_strdup(raux);
	return (str);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	unsigned	int				nb;
	int							i;
	char						aux[12];
	char						*raux;
	char						*str;

	nb = n;
	i = 0;
	if (nb == 0)
		aux[i++] = '0';
	while (nb > 0)
	{
		aux[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	aux[i] = '\0';
	raux = ft_reverse_str_itoa(aux);
	str = ft_strdup(raux);
	return (str);
}

char	*ft_unsigned_long_itoa(unsigned long int n)
{
	unsigned	long	int		nb;
	int							i;
	char						aux[12];
	char						*raux;
	char						*str;

	nb = n;
	i = 0;
	if (nb == 0)
		aux[i++] = '0';
	while (nb > 0)
	{
		aux[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	aux[i] = '\0';
	raux = ft_reverse_str_itoa(aux);
	str = ft_strdup(raux);
	return (str);
}
