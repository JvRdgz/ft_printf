/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_type_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:13:59 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/12 17:00:04 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_numb(t_struct *ft_struct, int *d)
{
	int					d_aux;

	d_aux = *d;
	if (ft_struct->is_precision == 1 ||
	(ft_struct->is_width == 1 && ft_struct->zero_width_flag == 1 &&
	ft_struct->neg_width == 0))
		d_aux *= -1;
	if (d_aux == -2147483648 && (ft_struct->is_precision == 1 ||
	(ft_struct->is_width == 1 && ft_struct->zero_width_flag == 1 &&
	ft_struct->neg_width == 0)))
	{
		ft_putnbr_fd(214748364, 1);
		ft_putnbr_fd(8, 1);
		ft_struct->len += ft_strlen(ft_itoa(214748364)) + 1;
	}
	else
	{
		ft_putnbr_fd(d_aux, 1);
		ft_struct->len += ft_strlen(ft_itoa(d_aux));
	}
}

void	neg_widthdcase(t_struct *ft_struct, int *arg_len, int *d)
{
	int		len_arg;
	int		d_aux;

	len_arg = *arg_len;
	d_aux = *d;
	if (ft_struct->is_precision == 1)
		put_precision_dcase(ft_struct, &d_aux);
	aux_d_case(ft_struct, &d_aux);
	if (ft_struct->is_width == 1)
		width_dcase(ft_struct, &len_arg, &d_aux);
}

void	d_order(t_struct *ft_struct, int *arg_len, int *d)
{
	int					d_aux;
	int					len_arg;

	d_aux = *d;
	len_arg = *arg_len;
	if (ft_struct->neg_width == 1)
		neg_widthdcase(ft_struct, &len_arg, &d_aux);
	else if (ft_struct->zero_width_flag == 1)
	{
		put_precision_dcase(ft_struct, &d_aux);
		width_dcase(ft_struct, &len_arg, &d_aux);
		aux_d_case(ft_struct, &d_aux);
	}
	else
	{
		if (ft_struct->is_width == 1)
			width_dcase(ft_struct, &len_arg, &d_aux);
		if (ft_struct->is_precision == 1)
			put_precision_dcase(ft_struct, &d_aux);
		aux_d_case(ft_struct, &d_aux);
	}
}
