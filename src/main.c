/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:16:26 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 12:29:20 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_tile_size(t_map *map)
{
	if ((W_HEIGHT - 100) / (map->map_y - 1) * 3 < (W_WIDTH - 100) / \
		(map->map_x - 1))
	{
		map->tile_height = (W_HEIGHT - 100) / (map->map_y - 1);
		map->tile_width = map->tile_height * 3;
	}
	else
	{
		map->tile_width = (W_WIDTH - 100) / (map->map_x - 1);
		map->tile_height = map->tile_width / 3;
	}
}

static t_map	init_everything(char *file)
{
	t_map	map;

	map.mlx = mlx_init();
	if (!map.mlx)
		fdf_error("error: could not initialize mlx", &map);
	map.win = mlx_new_window(map.mlx, W_WIDTH, W_HEIGHT, "FdF");
	if (!map.win)
		fdf_error("error: could not create window", &map);
	map.img.img = mlx_new_image(map.mlx, W_WIDTH, W_HEIGHT);
	map.img.add = mlx_get_data_addr(map.img.img, &map.img.bpp, \
		&map.img.x_len, &map.img.endian);
	map.map_x = 0;
	map.map_y = 0;
	read_map(file, &map);
	map.x_mid = map.map_x / 2;
	map.y_mid = map.map_y / 2;
	map.tile_height = 0.0;
	map.tile_width = 0.0;
	set_tile_size(&map);
	map.x_offset = W_WIDTH / 2;
	map.y_offset = W_HEIGHT / 2;
	map.z_mult = map.tile_height / 8;
	map.mode = 1;
	return (map);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		fdf_error("usage: ./fdf [mapfile]\n", NULL);
	map = init_everything(av[1]);
	mlx_clear_window(map.mlx, map.win);
	draw_new_image(&map);
	mlx_key_hook(map.win, manage_keys, &map);
	mlx_loop(map.mlx);
}
