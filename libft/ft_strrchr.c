/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:45:31 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:19:33 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	while (index != 0)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index--;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)&s[index]);
	return (NULL);
}
