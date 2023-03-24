/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:00:23 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/23 16:29:50 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idst;
	size_t	srclen;
	size_t	isrc;

	idst = 0;
	isrc = 0;
	srclen = ft_strlen(src);
	while (dst[idst] != '\0' && idst < dstsize)
		idst++;
	if (idst + 1 >= dstsize)
		return (idst + srclen);
	while (src[isrc] != '\0' && idst < dstsize - 1)
	{
		dst[idst] = src[isrc];
		idst++;
		isrc++;
	}
	dst[idst] = '\0';
	while (src[isrc] != '\0')
	{
		isrc++;
		idst++;
	}
	return (idst);
}
