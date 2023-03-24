/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:41:38 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 15:41:39 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*content;
	size_t	index;

	content = (char *)s;
	index = 0;
	while (index < n)
	{
		content[index] = (char)c;
		index++;
	}
	return (s);
}
