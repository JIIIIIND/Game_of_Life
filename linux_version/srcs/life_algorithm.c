/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:26:34 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/07 14:52:01 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"
#include "draw_ui.h"
#include <stdlib.h>
#include <unistd.h>

int		get_live_neighbor(char **world, t_point point, int limit)
{
	int		result;
	int		x;
	int		y;

	x = point.x;
	y = point.y;
	result = 0;
	if ((x - 1 >= 0) && (y - 1 >= 0) && (world[y - 1][x - 1] > ' '))
		result++;
	if ((x - 1 >= 0) && (world[y][x - 1] > ' '))
		result++;
	if ((x - 1 >= 0) && (y + 1 < limit) && (world[y + 1][x - 1] > ' '))
		result++;
	if ((y - 1 >= 0) && (world[y - 1][x] > ' '))
		result++;
	if ((y + 1 < limit) && (world[y + 1][x] > ' '))
		result++;
	if ((x + 1 < limit) && (y - 1 >= 0) && (world[y - 1][x + 1] > ' '))
		result++;
	if ((x + 1 < limit) && (world[y][x + 1] > ' '))
		result++;
	if ((x + 1 < limit) && (y + 1 < limit) && (world[y + 1][x + 1] > ' '))
		result++;
	return (result);
}

char	check_alive(char **buf, t_point point, int neighbor)
{
	if (buf[point.y][point.x] > ' ')
	{
		if ((neighbor < 2) || (neighbor > 3))
			return (' ');
		else
			return (buf[point.y][point.x] > 126 ?
					33 : buf[point.y][point.x] + 1);
	}
	else
	{
		if (neighbor == 3)
			return ('*');
		else
			return (' ');
	}
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

void	next_generation(char ***world, int limit, char cnt)
{
	t_point	point;

	point.y = 0;
	while (point.y < limit)
	{
		point.x = 0;
		while (point.x < limit)
		{
			(world[(cnt + 1) % 2][point.y][point.x]) =
				check_alive(world[cnt % 2], point,
					get_live_neighbor(world[cnt % 2], point, limit));
			point.x++;
		}
		point.y++;
	}
}

int		life_algo(t_map *map)
{
	char		***world;
	int			limit;
	static int	cnt;

	world = map->world;
	limit = map->limit;
	put_buffer(map->cam.buffer, &(map->cam), world[map->cnt % 2]);
	draw_screen(world[map->cnt % 2], map->cam.buffer, &(map->cam), &(map->head));
	draw_panel(&(map->cam), map->limit, map->start);
	if (map->start == 0)
		return (0);
	if (cnt++ < map->speed)
		return (0);
	else
		cnt = 0;
	next_generation(world, limit, map->cnt);
	map->cnt = (map->cnt + 1) % 2;
	return (0);
}
