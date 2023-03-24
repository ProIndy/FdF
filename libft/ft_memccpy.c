/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:39:36 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 15:56:29 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				index;
	unsigned char		character;
	unsigned const char	*srccont;
	unsigned char		*dstcont;

	index = 0;
	character = (unsigned char)c;
	srccont = (unsigned const char *)src;
	dstcont = (unsigned char *)dst;
	while (index < n)
	{
		dstcont[index] = srccont[index];
		if (srccont[index] == character)
			return ((void *)&dstcont[index + 1]);
		index++;
	}
	return (NULL);
}
