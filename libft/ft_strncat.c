/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:08 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/23 15:43:00 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	is1;
	size_t	is2;

	is1 = 0;
	is2 = 0;
	while (s1[is1] != '\0')
		is1++;
	while (s2[is2] != '\0' && is2 < n)
	{
		s1[is1] = s2[is2];
		is1++;
		is2++;
	}
	s1[is1] = '\0';
	return (s1);
}
