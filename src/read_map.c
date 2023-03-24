/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:30:27 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:38:44 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_values_and_row(char ***values, char *row)
{
	int	i;

	ft_strdel(&row);
	i = 0;
	if (values && *values)
	{
		while ((*values)[i])
		{
			free((*values)[i]);
			i++;
		}
		free(*values);
	}
	values = NULL;
}

static t_point	**read_row(char **values, t_map *map, int y)
{
	t_point	**row;
	t_point	*point;
	int		x;

	row = (t_point **)malloc(sizeof(t_point *) * map->map_x);
	if (!row)
		return (NULL);
	x = 0;
	while (x < map->map_x)
	{
		point = (t_point *)malloc(sizeof(t_point));
		point->space_x = x;
		point->space_y = y;
		point->space_z = ft_atoi(values[x]);
		point->image_x = 0;
		point->image_y = 0;
		row[x] = point;
		x++;
	}
	return (row);
}

static void	read_values(int fd, int ret, t_map *map)
{
	char	**values;
	char	*row;
	int		i;

	map->array = (t_point ***)malloc(sizeof(t_point **) * map->map_y);
	if (!map->array)
		fdf_error("malloc fail\n", map);
	i = 0;
	while (i < map->map_y)
	{
		ret = get_next_line(fd, &row);
		if (ret < 1)
			fdf_error("read fail\n", map);
		values = ft_strsplit(row, ' ');
		if (!values)
			fdf_error("malloc fail\n", map);
		map->array[i] = read_row(values, map, i);
		if (!map->array[i])
			fdf_error("malloc fail\n", map);
		free_values_and_row(&values, row);
		i++;
	}
}

static void	get_map_dimensions(int fd, int ret, t_map *map)
{
	char	**values;
	char	*row;

	ret = get_next_line(fd, &row);
	if (ret < 1)
		fdf_error("not a file or file empty\n", map);
	values = ft_strsplit(row, ' ');
	if (!values)
		fdf_error("malloc fail\n", map);
	map->map_x = (int) ft_array_size((const void **)values);
	free_values_and_row(&values, row);
	while (ret)
	{
		ret = get_next_line(fd, &row);
		if (ret)
		{
			values = ft_strsplit(row, ' ');
			if (!values)
				fdf_error("malloc fail\n", map);
			if (((int) ft_array_size((const void **)values)) != map->map_x)
				fdf_error("invalid map\n", map);
			free_values_and_row(&values, row);
		}
		map->map_y++;
	}
}

void	read_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		fdf_error("failed to open given file\n", map);
	get_map_dimensions(fd, 0, map);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		fdf_error("failed to open given file\n", map);
	read_values(fd, 0, map);
	close(fd);
}
