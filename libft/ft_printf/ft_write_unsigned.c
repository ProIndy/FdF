/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:34 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:12:53 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	handle_prefix(t_conversion *conv, char *str)
{
	if (conv->hash == 1 || conv->type == 'p')
	{
		if (conv->type == 'o')
		{
			if (!(str[0] == '0' && str[1] == '\0' && conv->precision < 0))
			{
				conv->prefix = "0";
				conv->width -= 1;
				if (conv->hash)
					conv->precision--;
			}
		}
		else if (conv->type == 'x' || conv->type == 'X' || conv->type == 'p')
		{
			if (conv->type == 'p' || !(str[0] == '\0' || (str[0] == '0' && \
							str[1] == '\0')))
			{
				if (conv->type == 'X')
					conv->prefix = "0X";
				else
					conv->prefix = "0x";
				conv->width -= 2;
			}
		}
	}
}

static short int	get_value_len(unsigned long long int value, \
						unsigned char base)
{
	if ((value / base) == 0)
		return (1);
	else
		return (1 + get_value_len(value / base, base));
}

static unsigned char	get_base(char type)
{
	unsigned char	base;

	if (type == 'b')
		base = 2;
	if (type == 'o')
		base = 8;
	if (type == 'u')
		base = 10;
	if (type == 'x' || type == 'X' || type == 'p')
		base = 16;
	return (base);
}

static char	*printf_u_itoa_base(t_conversion *conv, \
			unsigned long long int value, char *str)
{
	unsigned char	base;
	short int		value_len;
	unsigned char	digit;

	base = get_base(conv->type);
	value_len = get_value_len(value, base);
	str[value_len] = '\0';
	value_len--;
	while (value_len >= 0)
	{
		digit = value % base;
		if (digit < 10)
			str[value_len] = digit + '0';
		else if (conv->type == 'p' || conv->type == 'x')
			str[value_len] = digit - 10 + 'a';
		else
			str[value_len] = digit - 10 + 'A';
		value /= base;
		value_len--;
	}
	if (str[0] == '0' && str[1] == '\0' && conv->precision == 0)
		str[0] = '\0';
	return (str);
}

void	ft_write_unsigned(t_conversion *conv, va_list args)
{
	char	str[64];

	if (conv->type == 'p')
		conv->type_size = 'L';
	if (conv->type_size == 'd')
		printf_u_itoa_base(conv, va_arg(args, unsigned int), str);
	else if (conv->type_size == 'H')
		printf_u_itoa_base(conv, (unsigned char)va_arg(args,
				unsigned int), str);
	else if (conv->type_size == 'h')
		printf_u_itoa_base(conv, (unsigned short)va_arg(args,
				unsigned int), str);
	else if (conv->type_size == 'l')
		printf_u_itoa_base(conv, va_arg(args, unsigned long int), str);
	else if (conv->type_size == 'L')
		printf_u_itoa_base(conv, va_arg(args,
				unsigned long long), str);
	handle_prefix(conv, str);
	if (conv->minus)
		ft_unsigned_output(conv, str);
	ft_write_width_unsigned(conv, str);
	if (!conv->minus)
		ft_unsigned_output(conv, str);
}
