/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:12:52 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 17:57:37 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pass(t_struct *ft_struct, const char *format)
{
	ft_struct->i++;
	ft_struct->is_width = 1;
	ft_struct->neg_width = 1;
	ft_struct->is_precision = 1;
	while (format[ft_struct->i] == '-')
		ft_struct->i++;
	ft_calculate_width(format, ft_struct);
}

void	ft_put_width(int *final_width, t_struct *ft_struct)
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

void	ft_calculate_width(const char *format, t_struct *ft_struct)
{
	ft_struct->is_flag = 1;
	ft_struct->is_width = 1;
	if (format[ft_struct->i] == '0')
	{
		ft_struct->zero_width_flag = 1;
		ft_struct->width = 0;
		while (format[ft_struct->i] == '0')
			ft_struct->i++;
	}
	if (ft_isdigit(format[ft_struct->i]) == 1 && format[ft_struct->i] != '0')
	{
		ft_struct->width = ft_atoi(&format[ft_struct->i]);
		ft_struct->i += ft_strlen(ft_itoa(ft_struct->width));
	}
}

void	ft_calculate_precision(const char *format, t_struct *ft_struct)
{
	int		j;
	char	*precision_read;
	char	*len_precision;
	int		i;

	i = 0;
	j = ft_struct->i;
	j++;
	while (format[j] > 47 && format[j] < 58)
		j++;
	len_precision = ft_itoa(j);
	precision_read = ft_calloc((ft_strlen(len_precision) + 1), sizeof(char));
	while (ft_isdigit(format[ft_struct->i]) == 1)
		precision_read[i++] = format[ft_struct->i++];
	precision_read[i] = '\0';
	ft_struct->precision = ft_atoi(precision_read);
	if (!(ft_strchr("cspdiuxX", format[ft_struct->i])))
		ft_struct->i--;
	free(precision_read);
}

void	valid_precision(const char *format, t_struct *ft_struct)
{
	ft_struct->is_precision = 0;
	ft_struct->dot_flag = 1;
	ft_struct->is_flag = 1;
	while (format[ft_struct->i] == '.')
		ft_struct->i++;
	if (ft_isdigit(format[ft_struct->i]) == 1)
	{
		ft_struct->is_precision = 1;
		ft_struct->precision_is_valid = 0;
		ft_calculate_precision(format, ft_struct);
	}
	else if (ft_strchr("cspdiuxX", format[ft_struct->i]))
	{
		ft_struct->precision_is_valid = 1;
		ft_struct->is_type = 1;
	}
	else
		strange_case(format, ft_struct);
}
