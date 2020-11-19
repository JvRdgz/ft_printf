/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:11:13 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 18:03:20 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pass_flags(t_struct *ft_struct, const char *format)
{
	ft_struct->is_flag = 1;
	if (format[ft_struct->i] == '*')
		manage_star_flag(ft_struct, format);
	else if (format[ft_struct->i] == '#')
		ft_struct->hashtag_flag = 1;
	else if (format[ft_struct->i] == '+')
		ft_struct->plus_flag = 1;
	else if (format[ft_struct->i] == '-')
		neg_flag(ft_struct, format);
	else if (format[ft_struct->i] == ' ')
	{
		while (format[ft_struct->i] == ' ')
			ft_struct->i++;
		ft_struct->i--;
		ft_struct->space_flag = 1;
	}
	ft_struct->i++;
	ft_percentage_case(format, ft_struct);
}

void	ft_type(const char *format, t_struct *ft_struct)
{
	if (format[ft_struct->i] == 's')
		s_case(ft_struct);
	else if (format[ft_struct->i] == 'd' || format[ft_struct->i] == 'i')
		d_case(ft_struct);
	else if (format[ft_struct->i] == 'c')
		c_case(ft_struct);
	else if (format[ft_struct->i] == 'p')
		p_case(ft_struct);
	else if (format[ft_struct->i] == 'u')
		u_case(ft_struct);
	else if (format[ft_struct->i] == 'x')
		x_case(ft_struct);
	else if (format[ft_struct->i] == 'X')
		xx_case(ft_struct);
	else if (format[ft_struct->i] == '%')
		print_percentage(ft_struct);
}

void	ft_percentage_case(const char *format, t_struct *ft_struct)
{
	if (ft_isdigit(format[ft_struct->i]) == 1)
		ft_calculate_width(format, ft_struct);
	if (format[ft_struct->i] == '.')
		valid_precision(format, ft_struct);
	if (ft_strchr("cspdiuxX%", format[ft_struct->i]))
		ft_type(format, ft_struct);
	if (ft_strchr("*#+- ", format[ft_struct->i]))
		pass_flags(ft_struct, format);
	if (!(ft_strchr("*#+-", format[ft_struct->i])) &&
	ft_isdigit(format[ft_struct->i] == 0)
	&& format[ft_struct->i] != '.' &&
	!(ft_strchr("cspdiuxX%", format[ft_struct->i])) &&
	format[ft_struct->i] != ' ')
		ft_struct->len += write(1, &format[ft_struct->i], 1);
}

void	ft_reset_variables(t_struct *ft_struct)
{
	ft_struct->precision = 0;
	ft_struct->width = 0;
	ft_struct->is_precision = 0;
	ft_struct->is_width = 0;
	ft_struct->neg_width = 0;
	ft_struct->precision_is_valid = 0;
	ft_struct->hashtag_flag = 0;
	ft_struct->star_flag = 0;
	ft_struct->plus_flag = 0;
	ft_struct->dot_flag = 0;
	ft_struct->zero_width_flag = 0;
	ft_struct->is_flag = 0;
	ft_struct->is_type = 0;
	ft_struct->is_percentage_flag = 0;
	ft_struct->alone_char = 0;
	ft_struct->space_flag = 0;
}

int		ft_printf(const char *format, ...)
{
	t_struct	ft_struct;

	va_start(ft_struct.ap, format);
	ft_reset_variables(&ft_struct);
	ft_struct.i = 0;
	ft_struct.len = 0;
	while (format[ft_struct.i] != '\0')
	{
		if (format[ft_struct.i] == '%')
		{
			ft_reset_variables(&ft_struct);
			ft_struct.i++;
			if (format[ft_struct.i] == '\0')
				break ;
			else
				ft_percentage_case(format, &ft_struct);
		}
		else if (ft_struct.alone_char == 0)
			ft_struct.len += write(1, &format[ft_struct.i], 1);
		ft_struct.i++;
	}
	va_end(ft_struct.ap);
	return (ft_struct.len);
}
