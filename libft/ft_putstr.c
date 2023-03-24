/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:16:12 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 14:45:45 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(char const *s)
{
	int	index;

	if (s != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			write(1, &s[index], 1);
			index++;
		}
	}
}
