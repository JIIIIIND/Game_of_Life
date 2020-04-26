/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:24:25 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/26 20:30:43 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "game_of_life.h"
#include <stdio.h>

int		switch_flag(int val)
{
	if (val == 0)
		return (1);
	else
		return (0);
}

void	camera_move_up(t_map *map)
{
	if (map->cam.start.y > 0)
	{
		map->cam.start.y -= 1;
		map->cam.end.y -= 1;
	}
}

void	camera_move_down(t_map *map)
{
	int		limit;

	limit = map->limit - 1;
	if (map->cam.end.y < limit)
	{
		map->cam.end.y += 1;
		map->cam.start.y += 1;
	}
}

void	camera_move_left(t_map *map)
{
	if (map->cam.start.x > 0)
	{
		map->cam.start.x -= 1;
		map->cam.end.x -= 1;
	}
}

void	camera_move_right(t_map *map)
{
	int		limit;

	limit = map->limit - 1;
	if (map->cam.end.x < limit)
	{
		map->cam.end.x += 1;
		map->cam.start.x += 1;
	}
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
	return (0);
}
