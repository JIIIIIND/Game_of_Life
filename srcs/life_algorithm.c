/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:26:34 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/25 00:10:27 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		get_live_neighbor(char **world, int x, int y, int limit)
{
	int		result;

	result = 0;
	if ((x - 1 >= 0) && (y - 1 >= 0) && (world[y - 1][x - 1] == '*'))
		result++;
	if ((x - 1 >= 0) && (world[y][x - 1] == '*'))
		result++;
	if ((x - 1 >= 0) && (y + 1 < limit) && (world[y + 1][x - 1] == '*'))
		result++;
	if ((y - 1 >= 0) && (world[y - 1][x] == '*'))
		result++;
	if ((y + 1 < limit) && (world[y + 1][x] == '*'))
		result++;
	if ((x + 1 < limit) && (y - 1 >= 0) && (world[y - 1][x + 1] == '*'))
		result++;
	if ((x + 1 < limit) && (world[y][x + 1] == '*'))
		result++;
	if ((x + 1 < limit) && (y + 1 < limit) && (world[y + 1][x + 1] == '*'))
		result++;
	return (result);
}

char	check_alive(char **buf, int x, int y, int neighbor)
{
	if (buf[y][x] == '*')
	{
		if (neighbor < 2)
			return (' ');
		else if (neighbor > 3)
			return (' ');
		else
			return ('*');
	}
	else
	{
		if (neighbor == 3)
			return ('*');
	}
	return (' ');
}

void	update_planes(char ***world, int limit)
{
	int		idx_x;
	int		idx_y;

	idx_y = 0;
	while (idx_y < limit)
	{
		idx_x = 0;
		while (idx_x < limit)
		{
			world[0][idx_y][idx_x] = world[1][idx_y][idx_x];
			idx_x++;
		}
		idx_y++;
	}
}

int		life_algo(t_map *map)
{
	int		idx_x;
	int		idx_y;
	char	***world;
	int		limit;

	idx_y = 0;
	world = map->world;
	limit = map->limit;
	put_buffer(map->cam.buffer, &(map->cam), world[0]);
	draw_screen(map->cam.buffer, &(map->cam));
	print_plane(world[0], limit);
	while (idx_y < limit)
	{
		idx_x = 0;
		while (idx_x < limit)
		{
			(world[1][idx_y][idx_x]) = check_alive(world[0], idx_x, idx_y,
					get_live_neighbor(world[0], idx_x, idx_y, limit));
			idx_x++;
		}
		idx_y++;
	}
	update_planes(world, limit);
	sleep(1);
	return (0);
}
