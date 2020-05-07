/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:01:26 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/07 13:25:56 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"

void	save_camera_data(unsigned int **buf, t_point res, int fd)
{
	int		index;

	index = 0;
	while (index < res.y)
	{
		write(fd, buf[index], sizeof(unsigned int) * res.x);
		index++;
	}
}

void	save_map_data(char ***world, int limit, int fd)
{
	int		index;

	index = 0;
	while (index < limit)
	{
		ft_putstr_fd(world[0][index], fd);
		ft_putstr_fd(world[1][index], fd);
		index++;
	}
}

void	save_file(t_map *map, char *path)
{
	int			fd;
	t_map_data	md;
	t_cam_data	cd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
	{
		md.limit = map->limit;
		md.speed = map->speed;
		md.cnt = map->cnt;
		write(fd, (&md), sizeof(md));
		save_map_data(map->world, map->limit, fd);
		cd.start.x = map->cam.start.x;
		cd.start.y = map->cam.start.y;
		cd.end.x = map->cam.end.x;
		cd.end.y = map->cam.end.y;
		cd.res.x = map->cam.res.x;
		cd.res.y = map->cam.res.y;
		cd.cell_size = map->cam.cell_size;
		write(fd, (&cd), sizeof(cd));
		save_camera_data(map->cam.buffer, map->cam.res, fd);
	}
	close(fd);
}
