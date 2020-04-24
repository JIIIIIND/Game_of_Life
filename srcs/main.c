/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:19:04 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/25 00:28:56 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_of_life.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	map.cam.end.x = map.limit;
	map.cam.end.y = map.limit;
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

	map.world[0][2][3] = '*';
	map.world[0][2][2] = '*';
	map.world[0][2][4] = '*';

	map.world[0][10][10] = '*';
	map.world[0][10][11] = '*';
	map.world[0][11][9] = '*';
	map.world[0][11][10] = '*';
	map.world[0][12][10] = '*';

	win_main(&(map.cam));
	map.cam.cell_size = (double)map.limit / (double)map.cam.res.x;
	printf("%f\n", map.cam.cell_size);
	mlx_loop_hook(map.cam.mlx, life_algo, (void *)(&map));
	mlx_loop(map.cam.mlx);
}
