/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:29 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:40:30 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_conversions(const char *format)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			counter++;
			if (format[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (counter);
}

static int	ft_handle_conversion(va_list args, const char *format, int format_i)
{
	t_conversion	conv;

	ft_init_conv(&conv);
	ft_parse_conv(format, format_i, &conv);
	ft_write_conv(args, &conv);
	return (conv.length);
}

static int	ft_handle_format(va_list args, const char *format)
{
	int	format_i;
	int	temp_i;
	int	print_length;

	format_i = 0;
	print_length = 0;
	while (format[format_i] != '\0')
	{
		if (format[format_i] == '%')
		{
			temp_i = format_i;
			format_i += ft_check_conversion_validity(format, format_i);
			if (format_i != temp_i + 1)
				print_length += ft_handle_conversion(args, format, temp_i);
		}
		else
		{
			write(1, &format[format_i], 1);
			format_i++;
			print_length++;
		}
	}
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			nb_of_conversions;
	int			print_length;

	nb_of_conversions = ft_count_conversions(format);
	(void)nb_of_conversions;
	va_start(args, format);
	print_length = ft_handle_format(args, format);
	va_end(args);
	return (print_length);
}
