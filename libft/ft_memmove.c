/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:41:01 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:00:24 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
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
		if (&dstcont[0] == &srccont[index])
		{
			while (n)
			{
				n--;
				dstcont[n] = srccont[n];
			}
			return (dst);
		}
		index++;
	}
	dst = ft_memcpy(dst, src, n);
	return (dst);
}
