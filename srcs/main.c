/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:19:04 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/22 23:55:08 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_of_life.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	char	***world;
	int		index;
	int		w_idx;

	index = 0;
	w_idx = 0;
	if (argc != 2)
		return (0);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[1]);
	world = (char ***)malloc(sizeof(char **) * 2);
	while (w_idx < 2)
	{
		world[w_idx] = (char **)malloc(sizeof(char *) * y);
		index = 0;
		while (index < y)
		{
			world[w_idx][index] = (char *)malloc(sizeof(char) * x + 1);
			ft_memset(world[w_idx][index], ' ', x);
			world[w_idx][index][x] = 0;
			index++;
		}
		w_idx++;
	}

	world[0][2][3] = '*';
	world[0][2][2] = '*';
	world[0][2][4] = '*';

	world[0][10][4] = '*';
	world[0][10][5] = '*';
	world[0][11][3] = '*';
	world[0][11][4] = '*';
	world[0][12][4] = '*';

	index = 0;
	while (1)
	{
		print_plane(world[0], x);
		life_algo(world, x);
		sleep(1);
		index++;
	}
}
