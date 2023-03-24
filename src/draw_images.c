/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:22:18 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:22:57 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	clear_image(t_map *map)
{
	int	row;
	int	col;
	int	*pxl;

	row = 0;
	while (row < W_HEIGHT)
	{
		col = 0;
		while (col < W_WIDTH)
		{
			pxl = map->img.add + (row * map->img.x_len + col * \
					(map->img.bpp / 8));
			*pxl = 0x000000;
			col++;
		}
		row++;
	}
}

void	pixel_put_to_image(t_map *map, int x, int y)
{
	int	*pxl;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		pxl = map->img.add + (y * map->img.x_len + x * (map->img.bpp / 8));
		*pxl = 0xFFFFFF;
	}
}

void	draw_image(t_map *map)
{
	define_image(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img, 0, 0);
	mlx_string_put(map->mlx, map->win, 20, 20, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(map->mlx, map->win, 20, 40, 0xFFFFFF, "Adjust height: -/+");
	mlx_string_put(map->mlx, map->win, 20, 60, 0xFFFFFF, "Zoom: Q/W");
	mlx_string_put(map->mlx, map->win, 20, 80, 0xFFFFFF, \
			"Change projection: 1-3");
}

void	draw_new_image(t_map *map)
{
	clear_image(map);
	draw_image(map);
}
