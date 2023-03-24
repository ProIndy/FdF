/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:11 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:40:15 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_parse_type_size(const char *format, int i, t_conversion *conv)
{
	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
		{
			conv->type_size = 'L';
			i++;
		}
		else
			conv->type_size = 'l';
	}
	else if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
		{
			conv->type_size = 'H';
			i++;
		}
		else
			conv->type_size = 'h';
	}
	else if (format[i] == 'L')
		conv->type_size = 'D';
	return (i);
}

static int	ft_parse_width(const char *format, int i, t_conversion *conv)
{
	conv->width = ft_atoi(format + i);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	i--;
	return (i);
}

static int	ft_parse_precision(const char *format, int i, t_conversion *conv)
{
	i++;
	if (format[i] >= '1' && format[i] <= '9')
	{
		conv->precision = ft_atoi(format + i);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else
		conv->precision = 0;
	i--;
	return (i);
}

static int	ft_parse_flags(const char *format, int i, t_conversion *conv)
{
	while (!ft_valid_conv_type(format[i]))
	{
		if (format[i] == '-')
		{
			conv->minus = 1;
			if (conv->width_char == '0')
				conv->width_char = ' ';
		}
		else if (format[i] == '+')
			conv->plus = 1;
		else if (format[i] == ' ')
			conv->space = 1;
		else if (format[i] == '#')
			conv->hash = 1;
		else if (format[i] == '.')
			i = ft_parse_precision(format, i, conv);
		else if (format[i] == '0' && format[i - 1] != '.' && conv->minus == 0)
			conv->width_char = '0';
		else if (format[i] >= '1' && format[i] <= '9')
			i = ft_parse_width(format, i, conv);
		else if (format[i] == 'l' || format[i] == 'L' || format[i] == 'h')
			i = ft_parse_type_size(format, i, conv);
		i++;
	}
	return (i);
}

void	ft_parse_conv(const char *format, int format_i, t_conversion *conv)
{
	format_i++;
	format_i = ft_parse_flags(format, format_i, conv);
	conv->type = format[format_i];
}
