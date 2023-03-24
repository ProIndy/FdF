/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:45 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/16 16:32:56 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	size_t	index;
	char	*s2;

	length = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(*s2) * length + 1);
	if (!s2)
		return (NULL);
	else
	{
		index = 0;
		while (index < length)
		{
			s2[index] = s1[index];
			index++;
		}
		s2[index] = s1[index];
		return (s2);
	}
}
