/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:43:32 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:04:37 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_copy(char *res, char const *s, size_t resind)
{
	size_t	srcind;

	srcind = 0;
	while (s[srcind] != '\0')
	{
		res[resind] = s[srcind];
		srcind++;
		resind++;
	}
	return (resind);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	resind;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	resind = 0;
	res = (char *)malloc(sizeof(res) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	resind = ft_copy(res, s1, resind);
	resind = ft_copy(res, s2, resind);
	res[resind] = '\0';
	return (res);
}
