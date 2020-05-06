/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:19:04 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/05 20:04:55 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_of_life.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		clear_heap(t_map *map)
{
	int		index;
	
	index = 0;
	while (index < map->limit)
	{
		free((map->world)[0][index]);
		free((map->world)[1][index]);
		index++;
	}
	free((map->world)[0]);
	free((map->world)[1]);
	free(map->world);
	index = 0;
	while (index < (map->cam.res.y))
	{
		free((map->cam.buffer)[index]);
		index++;
	}
	free(map->cam.buffer);
	mlx_destroy_window(map->cam.mlx, map->cam.win);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_map		map;
	int			index;
	int			w_idx;

	index = 0;
	w_idx = 0;
	if (argc != 2)
		return (0);
	map.limit = ft_atoi(argv[1]);
	map.cam.start.x = 0;
	map.cam.start.y = 0;
	map.cam.end.x = map.limit / 2;
	map.cam.end.y = map.limit / 2;
	map.cnt = 0;
	map.start = 0;
	map.speed = 50;
	map.head = 0;
	map.world = (char ***)malloc(sizeof(char **) * 2);
	while (w_idx < 2)
	{
		map.world[w_idx] = (char **)malloc(sizeof(char *) * map.limit);
		index = 0;
		while (index < map.limit)
		{
			map.world[w_idx][index] = (char *)malloc(sizeof(char) * map.limit + 1);
			ft_memset(map.world[w_idx][index], ' ', map.limit);
			map.world[w_idx][index][map.limit] = 0;
			index++;
		}
		w_idx++;
	}
	map.event.old.x = 0;
	map.event.old.y = 0;
	map.event.button = 0;
	win_main(&(map.cam));
	map.cam.cell_size = (double)(map.cam.end.x - map.cam.start.x) / (double)map.cam.res.x;
	mlx_hook(map.cam.win, MotionNotify, PointerMotionMask, mouse_event, (void *)(&map));
	mlx_hook(map.cam.win, ButtonRelease, ButtonReleaseMask, mouse_release, (void *)(&map));
	mlx_mouse_hook(map.cam.win, mouse_click, (void *)(&map));
	mlx_hook(map.cam.win, KeyPress, KeyPressMask, keyboard_event, (void *)(&map));
	mlx_loop_hook(map.cam.mlx, life_algo, (void *)(&map));
	mlx_loop(map.cam.mlx);
}