/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:59:20 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/04 14:51:34 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "game_of_life.h"
#include "draw_ui.h"
#include "mlx.h"
#include <math.h>

unsigned int	get_color(char **map, int x, int y)
{
	if (map[y][x] == '*')
		return (0x00FFFFFF);
	else
		return (0x00000000);
}

void			put_buffer(unsigned int **buffer, t_camera *cam, char **map)
{
	int				buf_x;
	int				buf_y;
	double			map_x;
	double			map_y;

	buf_x = 0;
	map_x = cam->start.x;
	while (buf_x < cam->res.x)
	{
		buf_y = 0;
		map_y = cam->start.y;
		while (buf_y < cam->res.y)
		{
			buffer[buf_y][buf_x] = get_color(map, (int)map_x, (int)map_y);
			buf_y++;
			map_y += cam->cell_size;
			if (map_y > cam->end.y)
				map_y = cam->end.y;
		}
		buf_x++;
		map_x += cam->cell_size;
		if (map_x > cam->end.x)
			map_x = cam->end.x;
	}
}

void			draw_squre(t_point *point, t_camera *cam, char **map)
{
	double		size;
	t_point		pixel;
	t_point		index;

	size = ((double)cam->res.x / (double)(cam->end.x - cam->start.x));
	pixel.y = (int)((point->y - cam->start.y) * size);
	index.y = (int)(pixel.y + size);
	while (pixel.y < index.y)
	{
		pixel.x = (int)((point->x - cam->start.x) * size);
		index.x = (int)(pixel.x + size);
		while (pixel.x < index.x)
		{
			mlx_pixel_put(cam->mlx, cam->win, pixel.x, pixel.y,
					get_color(map, point->x, point->y));
					
			pixel.x += 1;
		}
		pixel.y += 1;
	}
}

void			delete_point(void *point)
{
	free(((t_point *)point));
}

void			draw_screen(char **map, unsigned int **buffer, t_camera *cam, t_list **lst)
{
	t_list	*node;
	int		x;
	int		y;

	node = *lst;
	if (node != 0)
	{
		while (node != 0)
		{
			draw_squre((t_point *)(node->content), cam, map);
			node = node->next;
		}
		ft_lstclear(lst, &delete_point);
	}
	else
	{
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
}
