/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:27 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:41:28 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	write_str(t_conversion *conv, char *str, int str_len)
{
	if (conv->precision > 0 && str_len > conv->precision)
		conv->length += write(1, str, conv->precision);
	else
		conv->length += write(1, str, str_len);
}

void	ft_write_string(t_conversion *conv, va_list args)
{
	char	*str;
	int		printed;
	int		str_len;

	printed = conv->width;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (conv->precision == 0)
		str = "";
	str_len = ft_strlen(str);
	if (conv->precision > 0 && str_len > 0 && conv->width > 0
		&& str_len > conv->precision)
		printed -= conv->precision;
	else if (conv->width)
		printed -= str_len;
	if (conv->minus)
		write_str(conv, str, str_len);
	while (printed-- > 0)
		conv->length += write(1, &conv->width_char, 1);
	if (!conv->minus)
		write_str(conv, str, str_len);
}	
