/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:01 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 15:58:54 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*s1cont;
	const unsigned char	*s2cont;

	s1cont = (const unsigned char *)s1;
	s2cont = (const unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (s1cont[index] != (s2cont[index]))
			return (s1cont[index] - s2cont[index]);
		index++;
	}
	return (0);
}
