/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:45:18 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:19:00 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hind;
	size_t	nind;

	hind = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[hind] != '\0')
	{
		nind = 0;
		while (haystack[hind + nind] != '\0' && needle[nind] != '\0' && \
			(hind + nind) < len && haystack[hind + nind] == needle[nind])
			nind++;
		if (needle[nind] == '\0')
			return ((char *)&haystack[hind]);
		hind++;
	}
	return (NULL);
}
