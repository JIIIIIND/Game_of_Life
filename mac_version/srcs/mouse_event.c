/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:40:36 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/08 12:14:30 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game_of_life.h"
#include "draw_btn.h"
#include <stdlib.h>

void	switch_value(char **world, t_point point, t_list **head)
{
	t_point	*pnt;

	pnt = (t_point *)malloc(sizeof(t_point));
	pnt->x = point.x;
	pnt->y = point.y;
	ft_lstadd_back(head, ft_lstnew(pnt));
	if (world[point.y][point.x] == '*')
		world[point.y][point.x] = ' ';
	else
		world[point.y][point.x] = '*';
}

int		mouse_release(int button, int x, int y, void *p)
{
	t_map		*map;

	map = (t_map *)p;
	if (button == 1)
	{
		if (x > 512 && x < 612)
			btn_check(button, x, y, map);
		map->event.button = 0;
		map->event.old.x = -1;
		map->event.old.y = -1;
	}
	return (0);
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
		if (map->start == 0)
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
	t_point			point;
	t_map			*map;

	map = (t_map *)p;
	event = &(map->event);
	if (event->button == 1)
	{
		cam = &(map->cam);
		if (x >= cam->res.x || y >= cam->res.y || x < 0 || y < 0)
			return (0);
		point.x = (int)((double)(x * (cam->end.x - cam->start.x)) / (double)(cam->res.x) + cam->start.x);
		point.y = (int)((double)(y * (cam->end.y - cam->start.y)) / (double)(cam->res.y) + cam->start.y);
		if ((event->old.x == point.x) && (event->old.y == point.y))
			return (0);
		event->old.x = point.x;
		event->old.y = point.y;
		switch_value((map->world)[map->cnt % 2], point, &(map->head));
		put_buffer(cam->buffer, cam, (((t_map *)p)->world)[((t_map *)p)->cnt % 2]);
		draw_screen((map->world)[map->cnt % 2], cam->buffer, cam, &(map->head));
	}
	return (0);
}
