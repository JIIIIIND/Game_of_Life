/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:24:25 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/07 13:16:27 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "camera_move.h"
#include <stdio.h>

int		switch_flag(int val)
{
	if (val == 0)
		return (1);
	else
		return (0);
}

void	camera_zoom_in(t_map *map)
{
	if ((map->cam.end.x - map->cam.start.x) > 1)
	{
		map->cam.end.x -= 1;
		map->cam.end.y -= 1;
		map->cam.start.x += 1;
		map->cam.start.y += 1;
	}
	map->cam.cell_size = (double)(map->cam.end.x - map->cam.start.x) /
		(double)map->cam.res.x;
}

void	camera_zoom_out(t_map *map)
{
	int		limit;

	limit = map->limit - 1;
	if ((map->cam.end.x < limit) && (map->cam.end.y < limit))
	{
		map->cam.end.x += 1;
		map->cam.end.y += 1;
	}
	if ((map->cam.start.x > 0) && (map->cam.start.y > 0))
	{
		map->cam.start.x -= 1;
		map->cam.start.y -= 1;
	}
	if ((map->cam.start.x > 0) && (map->cam.end.y < limit))
	{
		map->cam.start.x -= 1;
		map->cam.end.y += 1;
	}
	if ((map->cam.end.x < limit) && (map->cam.start.y > 0))
	{
		map->cam.end.x += 1;
		map->cam.start.y -= 1;
	}
	map->cam.cell_size = (double)(map->cam.end.x - map->cam.start.x) /
		(double)map->cam.res.x;
}

int		keyboard_event(int key, void *p)
{
	t_map	*map;

	map = (t_map *)(p);
	if (key == 32)
		map->start = switch_flag(map->start);
	else if (key == 65361)
		camera_move_left(map);
	else if (key == 65362)
		camera_move_up(map);
	else if (key == 65363)
		camera_move_right(map);
	else if (key == 65364)
		camera_move_down(map);
	else if (key == 61)
		camera_zoom_in(map);
	else if (key == 45)
		camera_zoom_out(map);
	else if (key == 65307)
		close_event(map);
	return (0);
}
