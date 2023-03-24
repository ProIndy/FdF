/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validity_checkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:41 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:40:44 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_valid_conv_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '.' || c == 'l' \
	|| c == 'L' || c == 'h' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_valid_conv_type(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
	|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == 'F' \
	|| c == 'b')
		return (1);
	return (0);
}

int	ft_check_conversion_validity(const char *format, int format_i)
{
	int	char_jump;

	char_jump = 1;
	while (!ft_valid_conv_type(format[format_i + char_jump]))
	{
		if (ft_valid_conv_flag(format[format_i + char_jump]))
			char_jump++;
		else
			return (1);
	}
	return (char_jump + 1);
}
