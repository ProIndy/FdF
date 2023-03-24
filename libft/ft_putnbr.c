/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:04:55 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 16:53:02 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_putnbrmin(void)
{
	char	c;

	c = '2';
	write(1, &c, 1);
	ft_putnbr(147483648);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		if (n == -2147483648)
			ft_putnbrmin();
		else
			ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			c = n + '0';
			write(1, &c, 1);
		}
	}
}
