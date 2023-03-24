/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:52:17 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 20:01:33 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_putnbrmin_fd(int fd)
{
	char	c;

	c = '2';
	write(fd, &c, 1);
	ft_putnbr_fd(147483648, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		if (n == -2147483648)
			ft_putnbrmin_fd(fd);
		else
			ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			c = n + '0';
			write(fd, &c, 1);
		}
	}
}
