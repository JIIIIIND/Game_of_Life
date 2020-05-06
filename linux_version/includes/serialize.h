/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:40:03 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 21:28:35 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_H
# define SERIALIZE_H
# pragma pack(push, 1)
# include "game_of_life.h"

typedef struct	s_map_data
{
	int			limit;
	int			speed;
	char		cnt;
}				t_map_data;

typedef struct	s_cam_data
{
	t_point		start;
	t_point		end;
	t_point		res;
	double		cell_size;
}				t_cam_data;
# pragma pack(pop)

void			save_file(t_map *map, char *path);

#endif
