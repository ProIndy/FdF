/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:48 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:16:48 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	comp;

	if (s1 == NULL || s2 == NULL)
		return (0);
	comp = ft_strncmp(s1, s2, n);
	if (comp == 0)
		return (1);
	return (0);
}
