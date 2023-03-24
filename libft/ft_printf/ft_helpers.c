/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:44 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:39:47 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_without_decimals(t_conversion *conv, char *str)
{
	int	i;

	i = ft_numlen(conv->float_whole_nb);
	while (i-- > 0)
	{
		str[i] = conv->float_whole_nb % 10 + '0';
		conv->float_whole_nb /= 10;
	}
}

void	ft_float_output(t_conversion *conv, char *str)
{
	int	str_len;

	if ((conv->width_char == ' ' || conv->minus) && !conv->sign_written)
	{
		if (conv->neg || conv->space || (conv->plus && !conv->neg))
			ft_write_possible_mark_space(conv);
	}
	ft_putstr(str);
	if (!conv->precision && conv->hash && !conv->inf && !conv->nan)
	{
		write(1, ".", 1);
		conv->length++;
		conv->width--;
	}
	str_len = ft_strlen(str);
	conv->length += str_len;
}

void	ft_int_output(t_conversion *conv, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	conv->length += str_len;
	if (!conv->sign_written)
		ft_write_possible_mark_space(conv);
	if (conv->precision >= str_len)
	{
		str_len = conv->precision - str_len;
		while (str_len-- > 0)
		{
			write(1, "0", 1);
			conv->length++;
		}
	}
	ft_putstr(str);
}

void	ft_unsigned_output(t_conversion *conv, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	conv->length += str_len;
	if (conv->minus || conv->width_char == ' ')
		ft_putstr(conv->prefix);
	conv->length += ft_strlen(conv->prefix);
	if (conv->precision >= str_len)
	{
		str_len = conv->precision - str_len;
		while (str_len-- > 0)
		{
			write(1, "0", 1);
			conv->length++;
		}
	}
	ft_putstr(str);
}

void	ft_write_width_unsigned(t_conversion *conv, char *str)
{
	int		str_len;
	int		i;
	char	temp;

	temp = conv->width_char;
	str_len = ft_strlen(str);
	if (!conv->minus && conv->width_char == '0')
		ft_putstr(conv->prefix);
	if (conv->width > str_len || conv->width > conv->precision)
	{
		if (conv->width && conv->precision >= 0)
			temp = ' ';
		if (conv->precision >= str_len)
			i = conv->width - conv->precision;
		else
			i = conv->width - str_len;
		while (i-- > 0)
		{
			write(1, &temp, 1);
			conv->length++;
		}
	}
}
