/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_type_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:14:21 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/11 19:14:23 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_order(t_struct *ft_struct, unsigned int *arg_len, unsigned int *u)
{
	unsigned	int		u_aux;
	unsigned	int		len_arg;

	u_aux = *u;
	len_arg = *arg_len;
	if (ft_struct->is_precision == 1
	&& ft_struct->precision == 0 && u_aux == 0)
		len_arg--;
	if (ft_struct->neg_width == 1)
		neg_w_ucase(ft_struct, &len_arg, &u_aux);
	else if (ft_struct->zero_width_flag == 1)
	{
		put_precision_ucase(ft_struct, &u_aux);
		width_ucase(ft_struct, &len_arg);
		aux_u_case(ft_struct, &u_aux);
	}
	else
	{
		if (ft_struct->is_width == 1)
			width_ucase(ft_struct, &len_arg);
		if (ft_struct->is_precision == 1)
			put_precision_ucase(ft_struct, &u_aux);
		aux_u_case(ft_struct, &u_aux);
	}
}
