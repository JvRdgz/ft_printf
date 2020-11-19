/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:13:14 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/13 20:35:44 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_precision_scase(t_struct *ft_struct, char *str)
{
	str = ft_substr(str, 0, ft_struct->precision);
	ft_struct->len += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	put_scase(t_struct *ft_struct, char *s)
{
	ft_struct->is_type = 1;
	ft_putstr_fd(s, 1);
	ft_struct->len += ft_strlen(s);
}

void	width_scase(t_struct *ft_struct, char *str)
{
	int		final_width;
	int		len;

	len = ft_strlen(str);
	if (ft_struct->precision > (unsigned int)len)
		final_width = ft_struct->width - len;
	else
		final_width = ft_struct->width - ft_struct->precision;
	ft_put_width(&final_width, ft_struct);
}

void	neg_widthscase(t_struct *ft_struct, int *arg_len, char *str)
{
	int						len_arg;

	len_arg = *arg_len;
	if (ft_struct->is_precision == 1)
	{
		if (ft_struct->precision != 0)
			put_precision_scase(ft_struct, str);
	}
	else
		put_scase(ft_struct, str);
	if (ft_struct->is_width == 1 && ft_struct->is_precision == 0)
		general_width(ft_struct, &len_arg);
	if (ft_struct->is_width == 1 && ft_struct->is_precision == 1)
		width_scase(ft_struct, str);
}

void	s_case(t_struct *ft_struct)
{
	char						*s;
	int							len_arg;

	s = va_arg(ft_struct->ap, char *);
	if (s == NULL)
		s = "(null)";
	if (ft_struct->precision_is_valid == 1)
		s = "";
	len_arg = ft_strlen(s);
	if (ft_struct->neg_width == 1)
		neg_widthscase(ft_struct, &len_arg, s);
	else
	{
		if (ft_struct->is_width == 1 && ft_struct->is_precision == 0)
			general_width(ft_struct, &len_arg);
		if (ft_struct->is_width == 1 && ft_struct->is_precision == 1)
			width_scase(ft_struct, s);
		if (ft_struct->is_precision == 1)
		{
			if (ft_struct->precision != 0)
				put_precision_scase(ft_struct, s);
		}
		else
			put_scase(ft_struct, s);
	}
}
