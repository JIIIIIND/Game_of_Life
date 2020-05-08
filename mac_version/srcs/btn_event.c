/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:07:21 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/07 14:24:21 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"
#include "get_next_line.h"
#include "serialize.h"

void	save_load_event(t_map *map, void (*f)())
{
	char	*path;

	path = 0;
	ft_putstr_fd("input file name\n", 1);
	get_next_line(0, &path);
	(*f)(map, path);
	free(path);
}

int		btn_check(int button, int x, int y, t_map *map)
{
	if ((button == 1) && (x > 529) && (x < 592))
	{
		if ((y > 188) && (y < 251))
			map->start = ((map->start + 1) % 2);
		else if ((y > 268) && (y < 331))
		{
			if (map->speed > 0)
				map->speed -= 10;
		}
		else if ((y > 348) && (y < 411))
		{
			if (map->speed < 200)
				map->speed += 10;
		}
		else if ((y > 428) && (y < 450))
			save_load_event(map, &save_file);
		else if ((y > 468) && (y < 490))
			save_load_event(map, &load_file);
	}
	return (0);
}
