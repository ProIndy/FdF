/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:43:50 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:10:12 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*res;

	if (s != NULL)
	{
		index = 0;
		res = (char *)malloc(sizeof(*res) * (ft_strlen(s) + 1));
		if (!res)
			return (NULL);
		while (s[index] != '\0')
		{
			res[index] = ((*f)(s[index]));
			index++;
		}
		res[index] = '\0';
		return (res);
	}
	return ((char *)s);
}
