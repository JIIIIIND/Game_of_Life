/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:54:51 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 17:58:17 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

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
	int	limit;

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
	int	limit;

	limit = map->limit -1;
	if (map->cam.end.x < limit)
	{
		map->cam.end.x += 1;
		map->cam.start.x += 1;
	}
}
