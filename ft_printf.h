/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:10:56 by jarodrig          #+#    #+#             */
/*   Updated: 2020/11/14 18:24:18 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct		s_struct
{
	va_list			ap;
	unsigned int	len;
	int				i;
	int				width;
	int				is_width;
	unsigned int	precision;
	int				is_precision;
	int				neg_width;
	int				zero_width_flag;
	int				hashtag_flag;
	int				plus_flag;
	int				star_flag;
	int				space_flag;
	int				precision_is_valid;
	int				dot_flag;
	int				is_flag;
	int				is_type;
	int				is_percentage_flag;
	int				alone_char;
}					t_struct;

char				*ft_reverse_str_itoa(char *str);
char				*ft_itoa(int n);
char				*ft_unsigned_itoa(unsigned int n);
void				ft_put_unsigned_nbr(unsigned int nbr);
void				ft_putchar(const char c);
int					ft_printf(const char *format,
		...) __attribute__((format(printf,1,2)));
void				s_case(t_struct *ft_struct);
void				d_case(t_struct *ft_struct);
void				c_case(t_struct *ft_struct);
void				p_case(t_struct	*ft_struct);
void				u_case(t_struct *ft_struct);
void				x_case(t_struct *ft_struct);
void				xx_case(t_struct *ft_struct);
void				put_scase(t_struct *ft_struct, char *s);
void				ft_calculate_precision(const char *format,
		t_struct *ft_struct);
void				ft_calculate_width(const char *format,
		t_struct *ft_struct);
void				general_width(t_struct *ft_struct, int *arg_len);
void				width_dcase(t_struct *ft_struct, int *arg_len,
		int *d);
void				neg_arg_dcase(t_struct *ft_struct, int *arg_len,
		int *final_width);
void				width_ucase(t_struct *ft_struct,
		unsigned int *arg_len);
void				width_scase(t_struct *ft_struct, char *str);
void				width_pcase(t_struct *ft_struct, int *arg_len);
void				width_xcase(t_struct *ft_struct, char *hex);
void				ft_put_width(int *final_width, t_struct *ft_struct);
void				ft_put_width_pcase(int *final_width,
		t_struct *ft_struct);
void				ft_percentage_case(const char *format,
		t_struct *ft_struct);
void				ft_reset_variables(t_struct *ft_struct);
int					ft_count_digits_hex(unsigned long int *p);
char				*ft_reverse_str(const char *str);
char				*ft_hex_format_cap(unsigned long int p);
char				*ft_hex_format_lower(unsigned long int p);
char				*ft_concat_strs(char *init, const char *final);
void				aux_u_case(t_struct *ft_struct, unsigned int *u);
void				aux_d_case(t_struct *ft_struct, int *d);
void				put_precision_ucase(t_struct *ft_struct,
		unsigned int *u);
void				put_precision_scase(t_struct *ft_struct, char *str);
void				put_precision_dcase(t_struct *ft_struct, int *d);
void				put_precision_xcase(t_struct *ft_struct, char *hex);
void				put_precision_pcase(t_struct *ft_struct, char *mem);
void				ft_type(const char *format, t_struct *ft_struct);
void				neg_flag(t_struct *ft_struct, const char *format);
void				neg_widthdcase(t_struct *ft_struct, int *arg_len, int *d);
void				neg_widthpcase(t_struct *ft_struct, unsigned long int *p);
void				neg_widthscase(t_struct *ft_struct,
		int *arg_len, char *str);
void				neg_w_ucase(t_struct *ft_struct,
		unsigned int *arg_l, unsigned int *u);
void				neg_widthxcase(t_struct *ft_struct,
		char *hex, unsigned int *x);
void				pass(t_struct *ft_struct, const char *format);
void				zero_flag_pcase(t_struct *ft_struct,
		int *arg_len, char *str);
void				neg_widthccase(t_struct *ft_struct, char *c);
void				pass_flags(t_struct *ft_struct, const char *format);
void				print_percentage(t_struct *ft_struct);
char				*convert_p(t_struct *ft_struct, unsigned long int *p);
void				manage_star_flag(t_struct *ft_struct, const char *format);
void				manage_plus_flag(t_struct *ft_struct, int *d);
void				space_flag(t_struct *ft_struct, const char *format);
void				d_order(t_struct *ft_struct, int *arg_len, int *d);
void				u_order(t_struct *ft_struct,
		unsigned int *arg_len, unsigned int *u);
void				p_order(t_struct *ft_struct,
		unsigned long int *u);
void				wp_pcase(t_struct *ft_struct, unsigned long int *p);
void				valid_precision(const char *format, t_struct *ft_struct);
void				neg_numb(t_struct *ft_struct, int *d);
void				precision_p_case(t_struct *ft_struct,
		unsigned long int *p);
void				w_x_xx_case(t_struct *ft_struct, char *hex,
		unsigned int *x);
void				strange_case(const char *format, t_struct *ft_struct);

#endif
