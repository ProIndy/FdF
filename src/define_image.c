/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:20 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:17:37 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_lines(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x)
		{
			if (x < map->map_x - 1)
			{
				draw_line(map, map->array[y][x], map->array[y][x + 1]);
			}
			if (y < map->map_y - 1)
			{
				draw_line(map, map->array[y][x], map->array[y + 1][x]);
			}
			x++;
		}
		y++;
	}
}

static void	default_mode(t_map *map, int x, int y)
{
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x)
		{
			map->array[y][x]->image_x = map->x_offset + (((x - map->x_mid) - \
			(y - map->y_mid)) * (map->tile_width / 2));
			map->array[y][x]->image_y = (map->y_offset + (((x - map->x_mid) + \
			(y - map->y_mid)) * (map->tile_height / 3))) - \
			(map->array[y][x]->space_z * map->z_mult);
			pixel_put_to_image(map, map->array[y][x]->image_x, \
			map->array[y][x]->image_y);
			x++;
		}
		y++;
	}
}

static void	higher_mode(t_map *map, int x, int y)
{
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x)
		{
			map->array[y][x]->image_x = map->x_offset + (((x - map->x_mid) - \
			(y - map->y_mid)) * (map->tile_width / 2));
			map->array[y][x]->image_y = (map->y_offset + (((x - map->x_mid) + \
			(y - map->y_mid)) * (map->tile_height / 2))) - \
			(map->array[y][x]->space_z * map->z_mult);
			pixel_put_to_image(map, map->array[y][x]->image_x, \
			map->array[y][x]->image_y);
			x++;
		}
		y++;
	}
}

static void	level_mode(t_map *map, int x, int y)
{
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x)
		{
			map->array[y][x]->image_x = map->x_offset + ((x - map->x_mid) * \
			(map->tile_width / 2));
			map->array[y][x]->image_y = map->y_offset + ((y - map->y_mid) * \
			(map->tile_height / 2)) - \
			(map->array[y][x]->space_z * map->z_mult);
			pixel_put_to_image(map, map->array[y][x]->image_x, \
			map->array[y][x]->image_y);
			x++;
		}
		y++;
	}
}

void	define_image(t_map *map)
{
	if (map->mode == 1)
		default_mode(map, 0, 0);
	if (map->mode == 2)
		higher_mode(map, 0, 0);
	if (map->mode == 3)
		level_mode(map, 0, 0);
	draw_lines(map);
}
