/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:26:09 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 15:38:57 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl(char const *s)
{
	int		index;
	char	nl;

	if (s != NULL)
	{
		nl = '\n';
		index = 0;
		while (s[index] != '\0')
		{
			write(1, &s[index], 1);
			index++;
		}
		write(1, &nl, 1);
	}
}
