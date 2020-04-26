/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:40:36 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/26 20:16:58 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "mlx.h"
#include "game_of_life.h"
#include <stdio.h>

void	switch_value(char **world, int x, int y)
{
	if (world[y][x] == '*')
		world[y][x] = ' ';
	else
		world[y][x] = '*';
}

int		mouse_click(int button, int x, int y, void *p)
{
	t_map		*map;
	t_point		click;

	map = (t_map *)p;
	click.x = (int)((double)(x * (map->cam.end.x - map->cam.start.x)) /
			(double)(map->cam.res.x) + map->cam.start.x);
	click.y = (int)((double)(y * (map->cam.end.y - map->cam.start.y)) /
			(double)(map->cam.res.y) + map->cam.start.y);
	if (button == 1)
	{
		if (map->event.button == 1)
		{
			map->event.old.x = -1;
			map->event.old.y = -1;
			map->event.button = 0;
		}
		else
		{
			map->event.old.x = click.x - 1;
			map->event.old.y = click.y - 1;
			map->event.button = 1;
		}
	}
	return (0);
}

int		mouse_event(int x, int y, void *p)
{
	t_camera		*cam;
	t_key_event		*event;
	int				map_x;
	int				map_y;

	event = &(((t_map *)(p))->event);
	if (event->button == 1)
	{
		cam = &(((t_map *)p)->cam);
		if (x >= cam->res.x || y >= cam->res.y || x < 0 || y < 0)
			return (0);
		map_x = (int)((double)(x * (cam->end.x - cam->start.x)) / (double)(cam->res.x) + cam->start.x);
		map_y = (int)((double)(y * (cam->end.y - cam->start.y)) / (double)(cam->res.y) + cam->start.y);
		if ((event->old.x == map_x) && (event->old.y == map_y))
			return (0);
		event->old.x = map_x;
		event->old.y = map_y;
		switch_value((((t_map *)(p))->world)[0], map_x, map_y);
		put_buffer(cam->buffer, cam, (((t_map *)p)->world)[0]);
		draw_screen(cam->buffer, cam);
	}
	return (0);
}
