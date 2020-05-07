/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:19:04 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/07 15:39:49 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_of_life.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		close_event(t_map *map)
{
	clear_heap(map);
	mlx_destroy_window(map->cam.mlx, map->cam.win);
	exit(0);
}

void	clear_heap(t_map *map)
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
}

void	map_init(t_map *map, int limit)
{
	map->limit = limit;
	map->start = 0;
	map->cam.start.x = 0;
	map->cam.start.y = 0;
	map->cam.end.x = limit / 2;
	map->cam.end.y = limit / 2;
	map->cnt = 0;
	map->speed = 50;
	map->head = 0;
	map->event.old.x = 0;
	map->event.old.y = 0;
	map->event.button = 0;
}

void	map_alloc(t_map *map, int limit)
{
	int		index;
	int		w_idx;

	w_idx = 0;
	map->world = (char ***)malloc(sizeof(char **) * 2);
	while (w_idx < 2)
	{
		map->world[w_idx] = (char **)malloc(sizeof(char *) * limit);
		index = 0;
		while (index < limit)
		{
			map->world[w_idx][index] = (char *)malloc(sizeof(char) * limit + 1);
			ft_memset(map->world[w_idx][index], ' ', limit);
			map->world[w_idx][index][limit] = 0;
			index++;
		}
		w_idx++;
	}
}

int		main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
		return (0);
	map_init(&map, ft_atoi(argv[1]));
	map_alloc(&map, map.limit);
	win_main(&(map.cam));
	map.cam.cell_size = (double)(map.cam.end.x - map.cam.start.x) /
		(double)map.cam.res.x;
	mlx_hook(map.cam.win, MotionNotify, PointerMotionMask, mouse_event, (void *)(&map));
	mlx_hook(map.cam.win, ButtonRelease, ButtonReleaseMask, mouse_release, (void *)(&map));
	mlx_mouse_hook(map.cam.win, mouse_click, (void *)(&map));
	mlx_hook(map.cam.win, KeyPress, KeyPressMask, keyboard_event, (void *)(&map));
	mlx_loop_hook(map.cam.mlx, life_algo, (void *)(&map));
	mlx_loop(map.cam.mlx);
}
