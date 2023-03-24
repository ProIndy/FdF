/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:45:54 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 17:51:26 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		index;
	char	nl;

	if (s != NULL)
	{
		nl = '\n';
		index = 0;
		while (s[index] != '\0')
		{
			write(fd, &s[index], 1);
			index++;
		}
		write(fd, &nl, 1);
	}
}
