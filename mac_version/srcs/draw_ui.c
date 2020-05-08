/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:40:55 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/08 12:16:35 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "draw_btn.h"
#include "game_of_life.h"

void		put_color(char *data, t_point pos, int size_line,
						unsigned int color)
{
	data[pos.y * size_line + pos.x * 4 + 3] = color >> 24;
	data[pos.y * size_line + pos.x * 4 + 2] = (color & 0x00ff0000) >> 16;
	data[pos.y * size_line + pos.x * 4 + 1] = (color & 0x0000ff00) >> 8;
	data[pos.y * size_line + pos.x * 4] = (color & 0x000000ff);
}

void		draw_map_square(char *data, int width, t_point start, t_point end)
{
	int		x;
	int		y;
	t_point	pos;

	y = start.y;
	while (y < end.y)
	{
		pos.x = start.x;
		pos.y = y;
		put_color(data, pos, width, 0x00ffffff);
		pos.x = end.x;
		put_color(data, pos, width, 0x00ffffff);
		y++;
	}
	x = start.x;
	while (x < end.x)
	{
		pos.y = start.y;
		pos.x = x;
		put_color(data, pos, width, 0x00ffffff);
		pos.y = end.y;
		put_color(data, pos, width, 0x00ffffff);
		x++;
	}
}

void		draw_minimap(char *data, t_camera *cam, int width, int limit)
{
	t_point	start;
	t_point	end;
	t_point	map_start;
	t_point	map_end;
	double	ratio;

	start.x = 17;
	start.y = 17;
	end.x = 80;
	end.y = 80;
	draw_map_square(data, width, start, end);
	ratio = 64.0f / (double)(limit);
	map_start.x = (int)((double)(cam->start.x) * ratio) + 17;
	map_start.y = (int)((double)(cam->start.y) * ratio) + 17;
	map_end.x = (int)((double)(cam->end.x + 1) * ratio) + 17;
	map_end.y = (int)((double)(cam->end.y + 1) * ratio) + 17;
	draw_map_square(data, width, map_start, map_end);
}

void		put_panel(char *data, int width, int height)
{
	int		x;
	int		y;
	t_point	pos;

	y = 0;
	while (y < height)
	{
		pos.y = y;
		x = 0;
		while (x < width)
		{
			pos.x = x;
			put_color(data, pos, width, 0x00555555);
			x++;
		}
		y++;
	}
}

void		draw_panel(t_camera *cam, int limit, int start_flag)
{
	mlx_img_list_t	*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;

	img = mlx_new_image(cam->mlx, 100, 512);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	put_panel(data, size_line, 512);
	draw_minimap(data, cam, size_line, limit);
	draw_btn(cam->mlx, data, size_line, start_flag);
	mlx_put_image_to_window(cam->mlx, cam->win, img, 512, 0);
	mlx_destroy_image(cam->mlx, img);
}
