/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:14:43 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/11 21:37:05 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_p(t_struct *ft_struct, unsigned long int *p)
{
	unsigned	long	int		p_aux;
	char						*str;
	char						*mem_address;

	p_aux = *p;
	str = ft_hex_format_lower(p_aux);
	if (p_aux == 0 && ft_struct->dot_flag == 0)
		mem_address = "0x0";
	else
		mem_address = ft_concat_strs("0x", str);
	return (mem_address);
}

void	put_precision_pcase(t_struct *ft_struct, char *hex)
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

void	wp_pcase(t_struct *ft_struct, unsigned long int *p)
{
	int							len_arg;
	unsigned	long	int		p_aux;
	char						*str;

	p_aux = *p;
	str = ft_hex_format_lower(p_aux);
	len_arg = ft_strlen(str) + 2;
	width_pcase(ft_struct, &len_arg);
	ft_putstr_fd("0x", 1);
	ft_struct->len += 2;
	put_precision_xcase(ft_struct, str);
	ft_putstr_fd(str, 1);
	ft_struct->len += ft_strlen(str);
}

void	precision_p_case(t_struct *ft_struct, unsigned long int *p)
{
	unsigned	long	int		p_aux;
	char						*mem_address;

	p_aux = *p;
	if (p_aux == 0 && ft_struct->star_flag == 1 &&
	ft_struct->is_precision == 1)
	{
		ft_putstr_fd("0x0", 1);
		ft_struct->len += 3;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_struct->len += 2;
	}
	mem_address = ft_hex_format_lower(p_aux);
	put_precision_pcase(ft_struct, mem_address);
	ft_putstr_fd(mem_address, 1);
	ft_struct->len += ft_strlen(mem_address);
}

void	p_order(t_struct *ft_struct, unsigned long int *p)
{
	int							len_arg;
	unsigned	long	int		p_aux;
	char						*str;

	p_aux = *p;
	if (ft_struct->neg_width == 1 || ft_struct->zero_width_flag == 1)
		neg_widthpcase(ft_struct, &p_aux);
	else
	{
		if (ft_struct->is_precision == 0 && ft_struct->is_width == 1)
		{
			str = convert_p(ft_struct, &p_aux);
			len_arg = ft_strlen(str);
			width_pcase(ft_struct, &len_arg);
			ft_putstr_fd(str, 1);
			ft_struct->len += ft_strlen(str);
		}
		else if (ft_struct->is_precision == 1)
			wp_pcase(ft_struct, &p_aux);
	}
}
