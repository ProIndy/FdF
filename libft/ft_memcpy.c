/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:12 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 15:40:14 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	const char	*srccont;
	char		*dstcont;

	if (!src && !dst)
		return (NULL);
	index = 0;
	srccont = (const char *)src;
	dstcont = (char *)dst;
	while (index < n)
	{
		dstcont[index] = srccont[index];
		index++;
	}
	return (dst);
}
