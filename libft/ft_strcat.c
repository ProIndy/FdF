/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:32:06 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:01:08 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	is1;
	int	is2;

	is1 = 0;
	is2 = 0;
	while (s1[is1] != '\0')
		is1++;
	while (s2[is2] != '\0')
	{
		s1[is1] = s2[is2];
		is1++;
		is2++;
	}
	s1[is1] = s2[is2];
	return (s1);
}
