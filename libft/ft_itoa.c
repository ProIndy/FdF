/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:27:00 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 20:40:40 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_length_of_int(int n)
{
	int	length;

	length = 1;
	while ((n / 10) != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char	*ft_itoa_neg(int n)
{
	char	*s;
	int		length;
	int		index;

	n = -n;
	length = ft_length_of_int(n);
	index = length + 1;
	s = (char *)malloc(sizeof(*s) * (length + 2));
	if (!s)
		return (NULL);
	s[index] = '\0';
	while (index > 0)
	{
		index--;
		s[index] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	s[0] = '-';
	return (s);
}

static char	*ft_itoa_pos(int n)
{
	char	*s;
	int		length;
	int		index;

	length = ft_length_of_int(n);
	index = length;
	s = (char *)malloc(sizeof(*s) * (length + 1));
	if (!s)
		return (NULL);
	s[index] = '\0';
	while (index >= 0)
	{
		index--;
		s[index] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		index;

	if (n == -2147483648)
	{
		s = (char *)malloc(sizeof(*s) * 12);
		if (!s)
			return (NULL);
		s[0] = '-';
		s[1] = '2';
		index = 10;
		n = 147483648;
		while (index >= 2)
		{
			s[index] = (n % 10) + '0';
			n = n / 10;
			index--;
		}
		s[11] = '\0';
	}
	else if (n > -2147483648 && n < 0)
		s = ft_itoa_neg(n);
	else
		s = ft_itoa_pos(n);
	return (s);
}
