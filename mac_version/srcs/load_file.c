/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:07:59 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/08 12:20:03 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"
#include <stdlib.h>

void	load_buf_data(t_camera *cam, t_point res, int fd)
{
	int		index;

	index = 0;
	cam->buffer = (unsigned int **)malloc(sizeof(unsigned int *) * res.y);
	while (index < res.y)
	{
		cam->buffer[index] = (unsigned int *)malloc(sizeof(unsigned int) * res.x);
		read(fd, cam->buffer[index], res.x);
		index++;
	}
}

void	load_map_data(t_map *map, int limit, int fd)
{
	int		index;

	index = 0;
	clear_heap(map);
	map->world = (char ***)malloc(sizeof(char **) * 2);
	map->world[0] = (char **)malloc(sizeof(char *) * limit);
	map->world[1] = (char **)malloc(sizeof(char *) * limit);
	while (index < limit)
	{
		map->world[0][index] = (char *)ft_calloc(sizeof(char), limit + 1);
		read(fd, map->world[0][index], limit);
		map->world[1][index] = (char *)ft_calloc(sizeof(char), limit + 1);
		read(fd, map->world[1][index], limit);
		index++;
	}
}

void	init_cam(t_camera *cam, t_cam_data cd)
{
	cam->start = cd.start;
	cam->end = cd.end;
	cam->res = cd.res;
	cam->cell_size = cd.cell_size;
}

void	init_map(t_map *map, t_map_data md)
{
	map->limit = md.limit;
	map->speed = md.speed;
	map->cnt = md.cnt;
}

void	load_file(t_map *map, char *path)
{
	int			fd;
	t_map_data	md;
	t_cam_data	cd;
	
	fd = open(path, O_RDONLY);
	read(fd, &md, sizeof(t_map_data));
	load_map_data(map, md.limit, fd);
	read(fd, &cd, sizeof(t_cam_data));
	load_buf_data(&(map->cam), cd.res, fd);
	init_map(map, md);
	init_cam(&(map->cam), cd);
}
