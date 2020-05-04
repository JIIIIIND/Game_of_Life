/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:07:21 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/04 20:21:16 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"
#include <stdio.h>

int		btn_check(int button, int x, int y, t_map *map)
{
	if ((button == 1) && (x > 529) && (x < 593))
	{
		if ((y > 188) && (y < 252))
			map->start = ((map->start + 1) % 2);
		else if ((y > 269) && (y < 333))
		{
			if (map->speed > 0)
				map->speed -= 10;
		}
		else if ((y > 350) && (y < 414))
		{
			if (map->speed < 200)
				map->speed += 10;
		}
	}
	return (0);
}
