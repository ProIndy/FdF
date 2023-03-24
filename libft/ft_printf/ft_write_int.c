/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:08 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:41:10 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	length_of_n(unsigned long long n)
{
	int	length;

	length = 1;
	while ((n / 10) != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	printf_itoa(t_conversion *conv, unsigned long long n, char *str)
{
	int	i;

	i = length_of_n(n);
	str[i] = '\0';
	while (i >= 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	if (conv->neg || conv->space || (conv->plus && !conv->neg))
		conv->width--;
	if (str[0] == '0' && str[1] == '\0' && conv->precision == 0)
		str[0] = '\0';
	if (conv->minus)
		ft_int_output(conv, str);
	if (!conv->minus && !conv->sign_written)
		ft_write_possible_mark(conv);
	ft_write_width_int(conv, str);
	if (!conv->minus)
		ft_int_output(conv, str);
}

void	ft_write_int(t_conversion *conv, va_list args)
{
	char		str[20];
	long long	n;

	n = 0;
	if (conv->type_size == 'd')
		n = va_arg(args, int);
	else if (conv->type_size == 'H')
		n = (char)va_arg(args, int);
	else if (conv->type_size == 'h')
		n = (short)va_arg(args, int);
	else if (conv->type_size == 'l')
		n = va_arg(args, long int);
	else if (conv->type_size == 'L')
		n = va_arg(args, long long int);
	if (n >= 0)
		printf_itoa(conv, (unsigned long long)n, str);
	else
	{
		conv->neg = 1;
		printf_itoa(conv, (unsigned long long)-n, str);
	}
}
