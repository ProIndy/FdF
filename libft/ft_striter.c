/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:43:10 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/30 16:05:34 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	index;

	if (s && f)
	{
		index = 0;
		while (s[index] != '\0')
		{
			((*f)(&s[index]));
			index++;
		}
	}
}
