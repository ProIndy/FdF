/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:14:12 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/02/15 13:14:14 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_cpyc(char **dst, char *src, char endchar, int counter)
{
	char	c;
	int		ret;

	if (**dst)
	{
		c = **dst;
		(*dst)++;
		ret = ft_cpyc(dst, src, endchar, counter + 1);
	}
	else if (*src && *src != endchar)
	{
		c = *src;
		ret = ft_cpyc(dst, src + 1, endchar, counter + 1);
	}
	else
	{
		*dst = (char *)malloc(counter + 1);
		if (!*dst)
			return (-1);
		dst[0][counter] = 0;
		return (*src == endchar);
	}
	if (ret != -1)
		dst[0][counter] = c;
	return (ret);
}

static int	ft_join(int *ret, char **line, char *part)
{
	char	*temp;

	if (!*line)
	{
		*line = ft_strnew(0);
		if (!*line)
		{
			return (-1);
		}
	}
	temp = *line;
	*ret = ft_cpyc(line, part, '\n', 0);
	free(temp);
	return (*ret);
}

static int	ft_confirm_read(int *ret, int fd, char *buffer)
{
	*ret = read(fd, buffer, BUFFER_SIZE);
	return (*ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd > MAX_FD - 1)
	{
		return (-1);
	}
	*line = 0;
	ret = BUFFER_SIZE;
	while (buffer[fd][0] || ft_confirm_read(&ret, fd, buffer[fd]) > 0)
	{
		buffer[fd][ret] = 0;
		if (ft_join(&ret, line, buffer[fd]))
		{
			ft_strcpy(buffer[fd], ft_strchr(buffer[fd], '\n') + 1);
			return (ret);
		}
	buffer[fd][0] = 0;
	}
	if (ret < 0)
	{
		return (ret);
	}
	return (!!*line);
}
