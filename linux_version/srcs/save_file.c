/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:01:26 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 21:50:07 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	load_file(char *path)
{
	t_map_data	md;
	t_cam_data	cd;
	char		buf;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		read(fd, &md, sizeof(t_map_data));
		read(fd, &buf, 1);
		read(fd, &cd, sizeof(t_cam_data));
	}
	printf("limit :%d speed: %d cnt: %d\n", md.limit, md.speed, md.cnt);
	printf("start: %d %d end: %d %d res: %d %d cell_size: %f\n", cd.start.x, cd.start.y, cd.end.x, cd.end.y, cd.res.x, cd.res.y, cd.cell_size);
	close(fd);
}

void	save_file(t_map *map, char *path)
{
	int			fd;
	t_map_data	md;
	t_cam_data	cd;

	fd = open(path, O_WRONLY | O_CREAT | O_APPEND,
			S_IRWXU | S_IRWXG | S_IRWXO);
	printf("fd: %d\n", fd);
	if (fd > 0)
	{
		md.limit = map->limit;
		md.speed = map->speed;
		md.cnt = map->cnt;
		printf("md size: %ld\n", sizeof(md));
		write(fd, (&md), sizeof(md));
		write(fd, "\n", 1);
		cd.start.x = map->cam.start.x;
		cd.start.y = map->cam.start.y;
		cd.end.x = map->cam.end.x;
		cd.end.y = map->cam.end.y;
		cd.res.x = map->cam.res.x;
		cd.res.y = map->cam.res.y;
		cd.cell_size = map->cam.cell_size;
		printf("md size: %ld\n", sizeof(cd));
		write(fd, (&cd), sizeof(cd));
	}
	close(fd);
	load_file(path);
}
