/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:24:25 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/25 19:41:54 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "game_of_life.h"

int		switch_flag(int val)
{
	if (val == 0)
		return (1);
	else
		return (0);
}

int		keyboard_event(int key, void *p)
{
	t_map	*map;

	map = (t_map *)(p);
	printf("key: %d\n", key);
	map->start = switch_flag(map->start);
	return (0);
}
