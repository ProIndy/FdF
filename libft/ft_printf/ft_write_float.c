/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:59 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:11:50 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	with_decimals(t_conversion *conv, long double fl, char *str)
{
	int					print_d;
	int					i;
	unsigned long long	decimals;

	i = conv->precision;
	print_d = i;
	while (i-- > 0)
		fl *= 10;
	decimals = (unsigned long long)fl;
	i = ft_numlen(conv->float_whole_nb);
	while (conv->precision_over_20-- > 0)
		str[conv->precision_over_20 + print_d + i + 1] = '0';
	while (print_d-- > 0)
	{
		str[i + print_d + 1] = decimals % 10 + '0';
		decimals /= 10;
	}
	str[i] = '.';
	while (i-- >= 0)
	{
		str[i] = conv->float_whole_nb % 10 + '0';
		conv->float_whole_nb /= 10;
	}
}

static void	check_inf_nan(t_conversion *conv, long double fl)
{
	if (fl == 1.0 / 0.0)
	{
		if (conv->type == 'f')
			conv->inf = 1;
		else if (conv->type == 'F')
			conv->inf = 2;
		conv->precision = 0;
		conv->width_char = ' ';
	}
	if (fl != fl)
	{
		if (conv->type == 'f')
			conv->nan = 1;
		else if (conv->type == 'F')
			conv->nan = 2;
		conv->precision = 0;
		conv->width_char = ' ';
	}
}

static void	printf_ftoa(t_conversion *conv, long double fl, char *str)
{
	check_inf_nan(conv, fl);
	if (!conv->inf && !conv->nan)
	{
		if (!conv->precision)
			ft_without_decimals(conv, str);
		else
			with_decimals(conv, fl, str);
	}
	else
		str = ft_insert_inf_nan(conv, str);
	if ((conv->neg || conv->space || (conv->plus && !conv->neg)) && !conv->nan)
		conv->width--;
	if (!conv->precision && conv->hash && !conv->inf && !conv->nan)
		conv->width--;
	if (conv->minus)
		ft_float_output(conv, str);
	if (!conv->minus && conv->width_char == '0')
		ft_write_possible_mark_space(conv);
	ft_write_width_float(conv, str);
	if (!conv->minus)
		ft_float_output(conv, str);
}

static void	check_precision(t_conversion *conv)
{
	if (conv->precision == -1)
		conv->precision = 6;
	if (conv->precision > 20)
	{
		conv->precision_over_20 = conv->precision - 20;
		conv->precision = 20;
	}
	if (conv->precision_over_20 > 20)
		conv->precision_over_20 = 20;
}

void	ft_write_float(t_conversion *conv, va_list args)
{
	char				str[62];
	long double			fl;

	ft_bzero(str, 62);
	if (conv->type_size == 'D')
		fl = va_arg(args, long double);
	else
		fl = va_arg(args, double);
	if (fl < 0 || 1 / fl == 1 / -0.0)
	{
		conv->neg = 1;
		fl *= -1;
	}
	check_precision(conv);
	if (conv->type_size == 'D')
		fl = ft_long_rounding(conv, fl);
	else
		fl = ft_double_rounding(conv, fl);
	conv->float_whole_nb = (unsigned long long)fl;
	fl -= conv->float_whole_nb;
	printf_ftoa(conv, fl, str);
}
