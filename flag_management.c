/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:11:30 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 17:56:04 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_flag(t_struct *ft_struct, const char *format)
{
	ft_struct->is_width = 1;
	ft_struct->neg_width = 1;
	while (format[ft_struct->i] == '-')
		ft_struct->i++;
	ft_struct->i--;
}

void	print_percentage(t_struct *ft_struct)
{
	char	c;
	int		len_arg;

	ft_struct->is_percentage_flag = 1;
	c = '%';
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

void	manage_star_flag(t_struct *ft_struct, const char *format)
{
	int		j;

	j = ft_struct->i;
	ft_struct->star_flag = 1;
	while (format[j] == '*')
	{
		if (ft_struct->is_precision == 1)
			ft_struct->precision = va_arg(ft_struct->ap, unsigned int);
		else
		{
			if (ft_struct->space_flag == 0)
				ft_struct->is_width = 1;
			ft_struct->width = va_arg(ft_struct->ap, int);
			if (ft_struct->width < 0)
			{
				ft_struct->width *= -1;
				ft_struct->neg_width = 1;
			}
		}
		j++;
	}
	ft_struct->i = j - 1;
}

void	manage_plus_flag(t_struct *ft_struct, int *d)
{
	int		d_aux;

	d_aux = *d;
	if (d_aux > -1)
	{
		write(1, "+", 1);
		ft_struct->len++;
	}
}

void	space_flag(t_struct *ft_struct, const char *format)
{
	while (format[ft_struct->i] == ' ')
		ft_struct->i++;
	if (ft_isdigit(format[ft_struct->i]) == 0 && ft_struct->is_width == 0)
		ft_struct->len += write(1, " ", 1);
	ft_struct->i--;
}
