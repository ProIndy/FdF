/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:53 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:10:59 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_write_possible_mark(t_conversion *conv)
{
	if (conv->width_char == '0' && (conv->precision >= conv->width || \
				conv->precision == -1))
	{
		if (conv->neg)
		{
			write(1, "-", 1);
			conv->length++;
			conv->sign_written++;
		}
		else if (conv->plus)
		{
			write(1, "+", 1);
			conv->length++;
			conv->sign_written++;
		}
		else if (conv->space)
		{
			write(1, " ", 1);
			conv->length++;
			conv->sign_written++;
		}
	}
}

void	ft_write_possible_mark_space(t_conversion *conv)
{
	if (conv->neg && !conv->nan)
	{
		write(1, "-", 1);
		conv->length++;
		conv->sign_written++;
	}
	else if (conv->plus && !conv->nan)
	{
		write(1, "+", 1);
		conv->length++;
		conv->sign_written++;
	}
	else if (conv->space && !conv->nan)
	{
		write(1, " ", 1);
		conv->length++;
		conv->sign_written++;
	}
}

void	ft_write_width_int(t_conversion *conv, char *str)
{
	int	str_len;
	int	i;

	str_len = ft_strlen(str);
	if (conv->width > str_len || conv->width > conv->precision)
	{
		if (conv->precision != -1 && conv->width > conv->precision)
			conv->width_char = ' ';
		if (conv->precision >= str_len)
			i = conv->width - conv->precision;
		else
			i = conv->width - str_len;
		while (i-- > 0)
		{
			write(1, &conv->width_char, 1);
			conv->length++;
		}
	}
}

void	ft_write_width_float(t_conversion *conv, char *str)
{
	int	str_len;
	int	i;

	str_len = ft_strlen(str);
	if (conv->width > str_len)
	{
		i = conv->width - str_len;
		while (i-- > 0)
		{
			write(1, &conv->width_char, 1);
			conv->length++;
		}
	}
}

char	*ft_insert_inf_nan(t_conversion *conv, char *str)
{
	if (conv->inf == 1)
		str = "inf";
	else if (conv->nan == 1)
		str = "-nan";
	else if (conv->inf == 2)
		str = "INF";
	else if (conv->nan == 2)
		str = "-NAN";
	return (str);
}
