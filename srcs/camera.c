/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:59:20 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/26 20:08:31 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "game_of_life.h"
#include "mlx.h"

unsigned int	get_color(char **map, int x, int y)
{
	if (map[y][x] == '*')
		return (0x00FFFFFF);
	else
		return (0x00000000);
}

void			put_buffer(unsigned int **buffer, t_camera *cam, char **map)
{
	int		buf_x;
	int		buf_y;
	double	map_x;
	double	map_y;

	buf_x = 0;
	map_x = cam->start.x;
	while (buf_x < cam->res.x)
	{
		buf_y = 0;
		map_y = cam->start.y;
		if ((int)map_x < cam->end.x)
		{
			while (buf_y < cam->res.y)
			{
				if ((int)map_y < cam->end.y)
					buffer[buf_y][buf_x] = get_color(map, (int)map_x, (int)map_y);
				buf_y++;
				map_y += cam->cell_size;
			}
		}
		buf_x++;
		map_x += cam->cell_size;
	}
}

void			draw_screen(unsigned int **buffer, t_camera *cam)
{
	int		x;
	int		y;

	y = 0;
	while (y < cam->res.y)
	{
		x = 0;
		while (x < cam->res.x)
		{
			mlx_pixel_put(cam->mlx, cam->win, x, y, buffer[y][x]);
			x++;
		}
		y++;
	}
}
