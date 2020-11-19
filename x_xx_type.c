/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_xx_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:14:54 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 18:15:29 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_widthxcase(t_struct *ft_struct, char *hex, unsigned int *x)
{
	unsigned	int		x_aux;

	x_aux = *x;
	if (x_aux == 0 && ft_struct->is_precision == 0 &&
	ft_struct->precision_is_valid == 0)
	{
		hex = ft_concat_strs(hex, "0");
		ft_struct->len++;
	}
	if (ft_struct->is_precision == 1)
		put_precision_xcase(ft_struct, hex);
	ft_putstr_fd(hex, 1);
	if (ft_struct->is_width == 1)
		width_xcase(ft_struct, hex);
}

void	width_xcase(t_struct *ft_struct, char *hex)
{
	int		final_width;
	int		len_arg;
	int		aux_precision;

	aux_precision = ft_struct->precision;
	len_arg = ft_strlen(hex);
	if (ft_struct->is_precision == 1)
	{
		if (aux_precision < len_arg)
			final_width = ft_struct->width - len_arg;
		else
			final_width = ft_struct->width - aux_precision;
	}
	else
		final_width = ft_struct->width - len_arg;
	ft_put_width(&final_width, ft_struct);
}

void	put_precision_xcase(t_struct *ft_struct, char *hex)
{
	int							aux_precision;
	int							aux_digits;

	aux_precision = ft_struct->precision;
	aux_digits = ft_strlen(hex);
	while (aux_precision > aux_digits)
	{
		ft_putnbr_fd(0, 1);
		ft_struct->len++;
		aux_digits++;
	}
}

void	x_case(t_struct *ft_struct)
{
	unsigned	int				x;
	char						*hex;

	x = va_arg(ft_struct->ap, unsigned int);
	ft_struct->is_type = 1;
	hex = ft_hex_format_lower(x);
	if (ft_struct->is_precision == 1)
		ft_struct->zero_width_flag = 0;
	if (ft_struct->hashtag_flag == 1 && x != 0)
		hex = ft_concat_strs("0x", hex);
	if (ft_struct->neg_width == 1)
		neg_widthxcase(ft_struct, hex, &x);
	else
		w_x_xx_case(ft_struct, hex, &x);
	ft_struct->len += ft_strlen(hex);
}

void	xx_case(t_struct *ft_struct)
{
	unsigned	int				x;
	char						*hex;

	x = va_arg(ft_struct->ap, unsigned int);
	ft_struct->is_type = 1;
	hex = ft_hex_format_cap(x);
	if (ft_struct->is_precision == 1)
		ft_struct->zero_width_flag = 0;
	if (ft_struct->hashtag_flag == 1 && x != 0)
		hex = ft_concat_strs("0X", hex);
	if (ft_struct->neg_width == 1)
		neg_widthxcase(ft_struct, hex, &x);
	else
		w_x_xx_case(ft_struct, hex, &x);
	ft_struct->len += ft_strlen(hex);
}
