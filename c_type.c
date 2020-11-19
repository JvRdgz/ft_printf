/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:13:03 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/13 17:43:00 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_widthccase(t_struct *ft_struct, char *c)
{
	int						len_arg;
	char					c_aux;

	c_aux = *c;
	len_arg = 1;
	ft_putchar(c_aux);
	if (ft_struct->is_width == 1)
		general_width(ft_struct, &len_arg);
}

void	general_width(t_struct *ft_struct, int *respective_len)
{
	int		final_width;
	int		aux_len;

	aux_len = *respective_len;
	final_width = ft_struct->width - aux_len;
	ft_put_width(&final_width, ft_struct);
}

void	c_case(t_struct *ft_struct)
{
	char						c;
	int							len_arg;

	c = va_arg(ft_struct->ap, int);
	ft_struct->is_type = 1;
	if (ft_struct->neg_width == 1)
		neg_widthccase(ft_struct, &c);
	else
	{
		len_arg = 1;
		if (ft_struct->is_width == 1)
			general_width(ft_struct, &len_arg);
		ft_putchar(c);
	}
	ft_struct->len++;
}
