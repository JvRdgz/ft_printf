/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:13:26 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 18:10:40 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_arg_dcase(t_struct *ft_struct, int *arg_len, int *final_width)
{
	int		aux_precision_arg;
	int		aux_precision;

	aux_precision = ft_struct->precision;
	aux_precision_arg = aux_precision - *arg_len + 1;
	if (aux_precision_arg < 0 && aux_precision > (*arg_len - 1))
	{
		aux_precision_arg *= -1;
		*final_width = ft_struct->width - (*arg_len + aux_precision_arg);
	}
	else if (aux_precision_arg > -1 && aux_precision > (*arg_len - 1))
		*final_width = ft_struct->width - (*arg_len + aux_precision_arg);
	else
		*final_width = ft_struct->width - *arg_len;
}

void	width_dcase(t_struct *ft_struct, int *arg_len, int *d)
{
	int		final_width;
	int		aux_precision;

	aux_precision = ft_struct->precision;
	if (ft_struct->is_precision == 1)
	{
		if (*d < 0)
			neg_arg_dcase(ft_struct, arg_len, &final_width);
		else if (ft_struct->width > *arg_len && aux_precision < *arg_len
		&& aux_precision != *d)
			final_width = ft_struct->width - *arg_len;
		else if (*d > -1)
			final_width = ft_struct->width - aux_precision;
	}
	else
		final_width = ft_struct->width - *arg_len;
	if (ft_struct->is_precision == 1 && ft_struct->plus_flag == 1
		&& *d > -1)
		final_width--;
	ft_put_width(&final_width, ft_struct);
}

void	put_precision_dcase(t_struct *ft_struct, int *d)
{
	int					aux_precision;
	int					aux_digits;
	unsigned	int		d_aux;

	d_aux = *d;
	aux_precision = ft_struct->precision;
	aux_digits = ft_strlen(ft_itoa(d_aux));
	if (ft_struct->space_flag == 1 && ft_struct->is_width == 0)
		ft_struct->len += write(1, " ", 1);
	if (*d < 0)
	{
		ft_putchar('-');
		ft_struct->len++;
		aux_digits--;
	}
	if (ft_struct->plus_flag == 1)
		manage_plus_flag(ft_struct, d);
	while (aux_precision > aux_digits)
	{
		ft_putnbr_fd(0, 1);
		aux_digits++;
		ft_struct->len++;
	}
}

void	aux_d_case(t_struct *ft_struct, int *d)
{
	int					d_aux;

	d_aux = *d;
	if (d_aux < 0)
		neg_numb(ft_struct, &d_aux);
	else if (ft_struct->is_precision == 1 &&
	ft_struct->precision == 0 && d_aux == 0)
		put_scase(ft_struct, "");
	else
	{
		if (ft_struct->plus_flag == 1 && ft_struct->is_precision == 0)
			manage_plus_flag(ft_struct, &d_aux);
		if (ft_struct->precision_is_valid == 1 && d_aux == 0)
			put_scase(ft_struct, "");
		else
		{
			if (ft_struct->space_flag == 1 && ft_struct->is_width == 0
			&& ft_struct->is_precision == 0)
				ft_struct->len += write(1, " ", 1);
			ft_putnbr_fd(d_aux, 1);
			ft_struct->len += ft_strlen(ft_itoa(d_aux));
		}
	}
}

void	d_case(t_struct *ft_struct)
{
	int							d;
	int							len_arg;

	d = va_arg(ft_struct->ap, int);
	ft_struct->is_type = 1;
	len_arg = ft_strlen(ft_itoa(d));
	if (ft_struct->precision_is_valid == 1)
		len_arg--;
	if (ft_struct->is_precision == 1)
		ft_struct->zero_width_flag = 0;
	if (ft_struct->is_width == 1 && ft_struct->plus_flag == 1
	&& d > -1)
		len_arg++;
	if (ft_struct->is_precision == 1 && ft_struct->is_width == 0)
		put_precision_dcase(ft_struct, &d);
	if (ft_struct->is_width == 1)
		d_order(ft_struct, &len_arg, &d);
	else
		aux_d_case(ft_struct, &d);
}
