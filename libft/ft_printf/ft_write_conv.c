/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:51 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:40:52 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_write_percent(t_conversion *conv)
{
	write(1, "%", 1);
	conv->length++;
}

static void	ft_write_char(t_conversion *conv, va_list args)
{
	char	c;
	int		printed;

	c = va_arg(args, int);
	if (conv->minus)
		write(1, &c, 1);
	if (conv->width != 0)
	{
		printed = conv->width - 1;
		conv->length = conv->width;
		while (printed-- > 0)
			write(1, &conv->width_char, 1);
	}
	else
		conv->length = 1;
	if (!conv->minus)
		write(1, &c, 1);
}

void	ft_write_conv(va_list args, t_conversion *conv)
{
	if (conv->type == '%')
		ft_write_percent(conv);
	else if (conv->type == 'c')
		ft_write_char(conv, args);
	else if (conv->type == 's')
		ft_write_string(conv, args);
	else if (conv->type == 'u' || conv->type == 'o' || conv->type == 'x' || \
		conv->type == 'X' || conv->type == 'p' || conv->type == 'b')
		ft_write_unsigned(conv, args);
	else if (conv->type == 'd' || conv->type == 'i')
		ft_write_int(conv, args);
	else if (conv->type == 'f' || conv->type == 'F')
		ft_write_float(conv, args);
	else
		ft_write_percent(conv);
}
