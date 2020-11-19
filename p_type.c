/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:14:33 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/13 17:43:12 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_width_pcase(int *final_width, t_struct *ft_struct)
{
	int		i;
	int		aux_width;

	aux_width = *final_width;
	i = 0;
	while (i < aux_width)
	{
		if (ft_struct->zero_width_flag == 1 && ft_struct->neg_width == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
		ft_struct->len++;
	}
}

void	width_pcase(t_struct *ft_struct, int *respective_len)
{
	int						final_width;
	int						aux_len;
	unsigned	int			aux_width;

	aux_len = *respective_len;
	aux_width = ft_struct->width;
	if (ft_struct->is_precision == 1)
	{
		if (aux_width > ft_struct->precision)
		{
			if ((int)ft_struct->precision > aux_len - 2)
				final_width = ft_struct->width - ft_struct->precision - 2;
			else if ((int)ft_struct->precision < aux_len)
				final_width = ft_struct->width - aux_len;
		}
		else
			final_width = ft_struct->width - ft_struct->precision;
	}
	else
		final_width = ft_struct->width - aux_len;
	ft_put_width_pcase(&final_width, ft_struct);
}

void	zero_flag_pcase(t_struct *ft_struct, int *arg_len, char *str)
{
	int						len_arg;

	len_arg = *arg_len;
	if (ft_struct->is_precision == 1)
		ft_struct->zero_width_flag = 0;
	width_pcase(ft_struct, &len_arg);
	ft_putstr_fd("0x", 1);
	ft_struct->len += 2;
	if (ft_struct->is_precision == 1)
		put_precision_pcase(ft_struct, str);
	ft_putstr_fd(str, 1);
}

void	neg_widthpcase(t_struct *ft_struct, unsigned long int *p)
{
	int							len_arg;
	unsigned	long	int		p_aux;
	char						*str;

	p_aux = *p;
	str = ft_hex_format_lower(p_aux);
	len_arg = ft_strlen(str) + 2;
	if (ft_struct->neg_width == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_struct->len += 2;
		put_precision_xcase(ft_struct, str);
		ft_putstr_fd(str, 1);
		width_pcase(ft_struct, &len_arg);
	}
	else if (ft_struct->zero_width_flag == 1)
		zero_flag_pcase(ft_struct, &len_arg, str);
	ft_struct->len += ft_strlen(str);
}

void	p_case(t_struct *ft_struct)
{
	unsigned	long	int		p;
	char						*mem_address;

	p = va_arg(ft_struct->ap, unsigned long int);
	ft_struct->is_type = 1;
	if (ft_struct->is_precision == 1 || ft_struct->is_width == 1)
	{
		if (ft_struct->is_precision == 1 && ft_struct->is_width == 0)
			precision_p_case(ft_struct, &p);
		else if (ft_struct->is_width == 1)
			p_order(ft_struct, &p);
	}
	else
	{
		mem_address = convert_p(ft_struct, &p);
		ft_putstr_fd(mem_address, 1);
		ft_struct->len += ft_strlen(mem_address);
	}
}
