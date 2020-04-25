/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:40:36 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/25 19:12:26 by jinwkim          ###   ########.fr       */
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

int		mouse_move(int button, int x, int y, void *p)
{
	t_camera	*cam;
	int			map_x;
	int			map_y;

	if (button == 1)
	{
		cam = &(((t_map *)p)->cam);
		map_x = (int)((double)(x * cam->end.x) / (double)(cam->res.x));
		map_y = (int)((double)(y * cam->end.y) / (double)(cam->res.y));
		switch_value((((t_map *)(p))->world)[0], map_x, map_y);
		put_buffer(cam->buffer, cam, (((t_map *)p)->world)[0]);
		draw_screen(cam->buffer, cam);
	}
	return (0);
}
