/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:59:20 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/29 23:25:26 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "game_of_life.h"
#include "mlx.h"
#include <math.h>

unsigned int	get_color(char **map, int x, int y)
{
	if (map[y][x] == '*')
		return (0x00FFFFFF);
	else
		return (0x00000000);
}

void			insert_node(t_list **lst, int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	ft_lstadd_back(lst, ft_lstnew(point));
}

void			put_buffer(unsigned int **buffer, t_camera *cam, char **map, t_list **lst)
{
	int				buf_x;
	int				buf_y;
	double			map_x;
	double			map_y;
	unsigned int	old;

	buf_x = 0;
	map_x = cam->start.x;
	while (buf_x < cam->res.x)
	{
		buf_y = 0;
		map_y = cam->start.y;
		while (buf_y < cam->res.y)
		{
			old = buffer[buf_y][buf_x];
			buffer[buf_y][buf_x] = get_color(map, (int)map_x, (int)map_y);
			if (old != buffer[buf_y][buf_x])
				insert_node(lst, buf_x, buf_y);
			buf_y++;
			map_y += cam->cell_size;
			if (map_y > cam->end.y)
				map_y = cam->end.y;
		}
		buf_x++;
		map_x += cam->cell_size;
		if (map_x > cam->end.x)
			map_x = cam->end.x;
	}
}
/*
void			draw_ui(unsigned int **buffer)
{

}
*/

void			delete_point(void *point)
{
	free(((t_point *)point));
}

void			draw_screen(unsigned int **buffer, t_camera *cam, t_list **lst)
{
	int		x;
	int		y;
	t_list	*node;

	node = *lst;
	printf("size: %d\n", ft_lstsize(*lst));
	if (node != 0)
	{
		while (node != 0)
		{
			x = ((t_point *)(node->content))->x;
			y = ((t_point *)(node->content))->y;
			mlx_pixel_put(cam->mlx, cam->win, x, y, buffer[y][x]);
			node = node->next;
		}
		ft_lstclear(lst, &delete_point);
	}
	/*
	else
	{
		y = 0;
		while (y < cam->res.y)
		{
			x = 0;
			while (x < cam->res.x)
			{
				mlx_pixel_put(cam->mlx, cam->win, x, y, buffer[y][x]);
				x++;
			}
			y++;
		}
	}
	*/
}
