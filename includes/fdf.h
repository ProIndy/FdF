/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:15:59 by ijaaskel          #+#    #+#             */
/*   Updated: 2022/10/13 14:16:05 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define W_WIDTH 1366
# define W_HEIGHT 768

typedef struct s_point
{
	int	space_x;
	int	space_y;
	int	space_z;
	int	image_x;
	int	image_y;
}		t_point;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
}		t_line;

typedef struct s_data
{
	void	*img;
	void	*add;
	int		bpp;
	int		x_len;
	int		endian;
}		t_data;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		map_x;
	int		x_mid;
	int		map_y;
	int		y_mid;
	t_point	***array;
	double	tile_width;
	double	tile_height;
	int		min_height;
	int		x_offset;
	int		y_offset;
	double	z_mult;
	int		mode;
}		t_map;

void	fdf_error(char *output, t_map *map);
void	fdf_exit(t_map *map);
int		manage_keys(int key, t_map *map);
void	read_map(char *file, t_map *map);
void	draw_new_image(t_map *map);
void	define_image(t_map *map);
void	pixel_put_to_image(t_map *map, int x, int y);
void	draw_line(t_map *map, t_point *start, t_point *end);

#endif
