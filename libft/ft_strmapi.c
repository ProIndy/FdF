/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:03 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:12:29 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*res;

	if (s != NULL)
	{
		index = 0;
		res = (char *)malloc(sizeof(*res) * (ft_strlen(s) + 1));
		if (!res)
			return (NULL);
		while (s[index] != '\0')
		{
			res[index] = ((*f)(index, s[index]));
			index++;
		}
		res[index] = '\0';
		return (res);
	}
	return ((char *)s);
}
