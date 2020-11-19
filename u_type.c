/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:14:11 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 18:10:39 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_ucase(t_struct *ft_struct, unsigned int *arg_len)
{
	int		final_width;
	int		len_arg;
	int		aux_precision;

	aux_precision = ft_struct->precision;
	len_arg = (int)*arg_len;
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

void	put_precision_ucase(t_struct *ft_struct, unsigned int *u)
{
	int					aux_precision;
	int					aux_digits;
	unsigned	int		u_aux;

	u_aux = *u;
	aux_precision = ft_struct->precision;
	aux_digits = ft_strlen(ft_unsigned_itoa(u_aux));
	if (aux_precision > aux_digits)
	{
		while (aux_precision > aux_digits)
		{
			ft_putnbr_fd(0, 1);
			aux_digits++;
			ft_struct->len++;
		}
	}
}

void	neg_w_ucase(t_struct *ft_struct, unsigned int *arg_l, unsigned int *u)
{
	unsigned	int		len_arg;
	unsigned	int		u_aux;

	len_arg = *arg_l;
	u_aux = *u;
	if (ft_struct->is_precision == 1)
		put_precision_ucase(ft_struct, &u_aux);
	aux_u_case(ft_struct, &u_aux);
	if (ft_struct->is_width == 1)
		width_ucase(ft_struct, &len_arg);
}

void	aux_u_case(t_struct *ft_struct, unsigned int *u)
{
	unsigned	int		u_aux;

	u_aux = *u;
	if (ft_struct->is_precision == 1 &&
	ft_struct->precision == 0 && u_aux == 0)
		put_scase(ft_struct, "");
	else if (ft_struct->precision_is_valid == 1 && u_aux == 0)
		put_scase(ft_struct, "");
	else
	{
		ft_put_unsigned_nbr(u_aux);
		ft_struct->len += ft_strlen(ft_unsigned_itoa(u_aux));
	}
}

void	u_case(t_struct *ft_struct)
{
	unsigned	int				u;
	unsigned	int				len_arg;

	u = va_arg(ft_struct->ap, int);
	ft_struct->is_type = 1;
	len_arg = ft_strlen(ft_unsigned_itoa(u));
	if (ft_struct->precision_is_valid == 1)
		len_arg--;
	if (ft_struct->is_precision == 1)
		ft_struct->zero_width_flag = 0;
	if (ft_struct->is_precision == 1 && ft_struct->is_width == 0)
		put_precision_ucase(ft_struct, &u);
	if (ft_struct->is_width == 1)
		u_order(ft_struct, &len_arg, &u);
	else
		aux_u_case(ft_struct, &u);
}
