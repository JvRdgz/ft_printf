/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_xx_type_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:15:06 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 18:15:27 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_digits_hex(unsigned long int *p)
{
	int					cont;
	unsigned	int		aux;

	cont = 0;
	aux = *p;
	while (aux > 0)
	{
		aux /= 16;
		cont++;
	}
	return (cont);
}

char	*ft_hex_format_cap(unsigned long int p)
{
	int							rest;
	unsigned	long	int		aux;
	char						*hex;
	int							cont;
	char						*result;

	aux = p;
	cont = ft_count_digits_hex(&aux);
	hex = ft_calloc(cont + 1, sizeof(char));
	cont = 0;
	while (aux > 0)
	{
		rest = 0;
		rest = aux % 16;
		if (rest < 10)
			hex[cont] = rest + 48;
		else
			hex[cont] = rest + 55;
		aux /= 16;
		cont++;
	}
	hex[cont] = '\0';
	result = ft_reverse_str(hex);
	free(hex);
	return (result);
}

char	*ft_hex_format_lower(unsigned long int p)
{
	int							rest;
	unsigned	long	int		aux;
	char						*hex;
	int							cont;
	char						*result;

	aux = p;
	cont = ft_count_digits_hex(&aux);
	hex = ft_calloc(cont + 1, sizeof(char));
	cont = 0;
	while (aux > 0)
	{
		rest = 0;
		rest = aux % 16;
		if (rest < 10)
			hex[cont] = rest + 48;
		else
			hex[cont] = rest + 87;
		aux /= 16;
		cont++;
	}
	hex[cont] = '\0';
	result = ft_reverse_str(hex);
	free(hex);
	return (result);
}

void	w_x_xx_case(t_struct *ft_struct, char *hex, unsigned int *x)
{
	unsigned	int		x_aux;

	x_aux = *x;
	if (x_aux == 0 && ft_struct->is_precision == 0 &&
	ft_struct->precision_is_valid == 0)
	{
		hex = ft_concat_strs(hex, "0");
		ft_struct->len++;
	}
	else if (x_aux == 0 && ft_struct->is_precision == 1 &&
	ft_struct->star_flag == 1)
	{
		hex = ft_concat_strs(hex, "0");
		ft_struct->len++;
	}
	if (ft_struct->is_width == 1)
		width_xcase(ft_struct, hex);
	if (ft_struct->is_precision == 1)
		put_precision_xcase(ft_struct, hex);
	ft_putstr_fd(hex, 1);
}
