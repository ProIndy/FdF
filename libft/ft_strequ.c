/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:42:59 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:05:02 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	comp;

	if (s1 == NULL || s2 == NULL)
		return (0);
	comp = ft_strcmp(s1, s2);
	if (comp == 0)
		return (1);
	return (0);
}
