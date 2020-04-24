/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 23:45:52 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/25 00:26:28 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "libft.h"
#include "game_of_life.h"

void		win_main(t_camera *cam)
{
	int	index;

	index = 0;
	cam->res.x = 512;
	cam->res.y = 512;
	cam->buffer = (unsigned int **)malloc(sizeof(unsigned int *) * cam->res.y);
	while (index < cam->res.y)
	{
		cam->buffer[index] =
			(unsigned int *)malloc(sizeof(unsigned int) * cam->res.x);
		index++;
	}
	cam->mlx = mlx_init();
	cam->win = mlx_new_window(cam->mlx, cam->res.x, cam->res.y, "test");
}
