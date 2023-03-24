/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:47:38 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/01/20 15:21:19 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_down(t_map *map, t_line line, int x)
{
	int	y;

	if (line.dy < 0)
	{
		y = line.y1;
		while (y++ <= line.y0)
			pixel_put_to_image(map, x, y);
	}
	else if (line.dy > 0)
	{
		y = line.y0;
		while (y++ <= line.y1)
			pixel_put_to_image(map, x, y);
	}
	else
		pixel_put_to_image(map, x, line.y0);
}

static void	draw_points_to_line(t_map *map, t_line line, int x)
{
	int	y;

	y = (((line.dy * (x - line.x0)) / line.dx) + line.y0);
	pixel_put_to_image(map, x, y);
}

static t_line	set_line(t_point *start, t_point *end)
{
	t_line	line;

	line.x0 = start->image_x;
	line.y0 = start->image_y;
	line.x1 = end->image_x;
	line.y1 = end->image_y;
	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	return (line);
}

void	draw_line(t_map *map, t_point *start, t_point *end)
{
	t_line	line;
	int		x;
	int		y;

	line = set_line(start, end);
	x = 0;
	if (line.x0 < line.x1)
	{
		while (x++ < W_WIDTH)
		{
			if (x >= line.x0 && x <= line.x1)
				draw_points_to_line(map, line, x);
		}
	}
	else if (line.x0 > line.x1)
	{
		while (x++ < W_WIDTH)
		{
			if (x <= line.x0 && x >= line.x1)
				draw_points_to_line(map, line, x);
		}
	}
	else
		draw_down(map, line, line.x0);
}
