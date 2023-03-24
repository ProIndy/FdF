/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:42:22 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 17:44:45 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	index;

	if (s != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			write(fd, &s[index], 1);
			index++;
		}
	}
}
