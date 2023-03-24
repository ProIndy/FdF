/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:30:08 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 15:20:13 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	image_move(t_map *map, int key)
{
	if (key == 126 || key == 0xff52)
		map->y_offset -= 10;
	else if (key == 125 || key == 0xff54)
		map->y_offset += 10;
	else if (key == 123 || key == 0xff51)
		map->x_offset -= 10;
	else if (key == 124 || key == 0xff53)
		map->x_offset += 10;
}

static void	image_zoom(t_map *map, int key)
{
	double	relation;

	relation = map->tile_height;
	if (key == 12 || key == 113)
		map->tile_width += 4.0;
	else if ((key == 13 || key == 119) && map->tile_height > 3)
		map->tile_width -= 4.0;
		map->tile_height = map->tile_width / 3;
		map->z_mult = map->tile_height / relation * map->z_mult;
}

static void	image_mode(t_map *map, int key)
{
	if (key == 18 || key == 49)
		map->mode = 1;
	else if (key == 19 || key == 50)
		map->mode = 2;
	else if (key == 20 || key == 51)
		map->mode = 3;
}

static void	z_height(t_map *map, int key)
{
	if (key == 43 || key == 24 || key == 69)
		map->z_mult += 0.5;
	else if (key == 45 || key == 27 || key == 78)
		map->z_mult -= 0.5;
}

int	manage_keys(int key, t_map *map)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53 || key == 0xff1b)
		fdf_exit(map);
	else if ((key >= 123 && key <= 126) || (key >= 0xff51 && key <= 0xff54))
		image_move(map, key);
	else if (key == 12 || key == 13 || key == 113 || key == 119)
		image_zoom(map, key);
	else if ((key >= 18 && key <= 20) || (key >= 49 && key <= 51))
		image_mode(map, key);
	else if (key == 24 || key == 27 || key == 69 || key == 78 || key == 43 || \
		key == 45)
		z_height(map, key);
	else
	{
		ft_putendl("Unmapped key");
		return (0);
	}
	draw_new_image(map);
	return (0);
}
