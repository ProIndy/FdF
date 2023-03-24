/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:45:10 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:27:02 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	hind;
	size_t	nind;

	hind = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[hind] != '\0')
	{
		nind = 0;
		while (haystack[hind + nind] != '\0' && \
				haystack[hind + nind] == needle[nind])
		{
			if (needle[nind + 1] == '\0')
				return ((char *)&haystack[hind]);
			nind++;
		}
		hind++;
	}
	return (NULL);
}
