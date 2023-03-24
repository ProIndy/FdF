/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:26:56 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:26:57 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_points(t_map *map)
{
	int	y;
	int	x;

	y = map->map_y - 1;
	while (y >= 0)
	{
		x = map->map_x - 1;
		while (x >= 0)
		{
			free(map->array[y][x]);
			x--;
		}
		free(map->array[y]);
		y--;
	}
	free(map->array);
}

void	fdf_error(char *output, t_map *map)
{
	ft_putstr_fd(output, 2);
	if (map)
	{
		if (map->mlx && map->img.img)
			mlx_destroy_image(map->mlx, map->img.img);
		if (map->mlx && map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->array && map->map_y > 0)
			free_points(map);
	}
	exit (0);
}

void	fdf_exit(t_map *map)
{
	if (map)
	{
		if (map->mlx && map->img.img)
			mlx_destroy_image(map->mlx, map->img.img);
		if (map->mlx && map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->array && map->map_y > 0)
			free_points(map);
	}
	exit (0);
}
