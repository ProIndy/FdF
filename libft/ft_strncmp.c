/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:29 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:15:32 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		result;

	index = 0;
	while ((unsigned const char)s1[index] == (unsigned const char)s2[index] && \
	(unsigned const char)s1[index] != '\0' && \
	(unsigned const char)s2[index] != '\0' && index < n - 1)
		index++;
	result = (unsigned const char)s1[index] - (unsigned const char)s2[index];
	return (result);
}
