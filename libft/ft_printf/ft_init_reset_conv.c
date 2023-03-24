/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_reset_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:03 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/07 16:40:04 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_conv(t_conversion *conv)
{
	conv->length = 0;
	conv->minus = 0;
	conv->plus = 0;
	conv->space = 0;
	conv->hash = 0;
	conv->precision = -1;
	conv->width_char = ' ';
	conv->width = 0;
	conv->type_size = 'd';
	conv->type = 'i';
	conv->prefix = "";
	conv->neg = 0;
	conv->precision_over_20 = 0;
	conv->float_whole_nb = 0;
	conv->rounding_val = 0.5;
	conv->inf = 0;
	conv->nan = 0;
	conv->sign_written = 0;
}
