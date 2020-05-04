/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_btn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:10:05 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/04 17:05:21 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "game_of_life.h"
#include "draw_ui.h"

void	draw_speed_down(void *mlx, char *data, int size_line, t_point start)
{
	void	*img;
	int		width;
	int		height;
	int		line;
	char	*img_data;

	img = mlx_xpm_file_to_image(mlx, "resource/speed_down.xpm", &width, &height);
	img_data = mlx_get_data_addr(img, &width, &line, &height);
	height = 0;
	while (height < 64)
	{
		width = 0;
		while (width < 64)
		{
			data[(start.y + height) * size_line + (start.x + width) * 4] =
				img_data[height * line + width * 4];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 1] =
				img_data[height * line + width * 4 + 1];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 2] =
				img_data[height * line + width * 4 + 2];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 3] =
				img_data[height * line + width * 4 + 3];
			width++;
		}
		height++;
	}
}

void	draw_speed_up(void *mlx, char *data, int size_line, t_point start)
{
	void	*img;
	int		width;
	int		height;
	int		line;
	char	*img_data;

	img = mlx_xpm_file_to_image(mlx, "resource/speed_up.xpm", &width, &height);
	img_data = mlx_get_data_addr(img, &width, &line, &height);
	height = 0;
	while (height < 64)
	{
		width = 0;
		while (width < 64)
		{
			data[(start.y + height) * size_line + (start.x + width) * 4] =
				img_data[height * line + width * 4];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 1] =
				img_data[height * line + width * 4 + 1];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 2] =
				img_data[height * line + width * 4 + 2];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 3] =
				img_data[height * line + width * 4 + 3];
			width++;
		}
		height++;
	}
}

void	draw_pause(void *mlx, char *data, int size_line, t_point start)
{
	void	*img;
	int		width;
	int		height;
	int		line;
	char	*img_data;

	img = mlx_xpm_file_to_image(mlx, "resource/pause.xpm", &width, &height);
	img_data = mlx_get_data_addr(img, &width, &line, &height);
	height = 0;
	while (height < 64)
	{
		width = 0;
		while (width < 64)
		{
			data[(start.y + height) * size_line + (start.x + width) * 4] =
				img_data[height * line + width * 4];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 1] =
				img_data[height * line + width * 4 + 1];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 2] =
				img_data[height * line + width * 4 + 2];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 3] =
				img_data[height * line + width * 4 + 3];
			width++;
		}
		height++;
	}
}

void	draw_start(void *mlx, char *data, int size_line, t_point start)
{
	void	*img;
	int		width;
	int		height;
	int		line;
	char	*img_data;

	width = 0;
	height = 0;
	img = mlx_xpm_file_to_image(mlx, "resource/start.xpm", &width, &height);
	img_data = mlx_get_data_addr(img, &width, &line, &height);
	height = 0;
	while (height < 64)
	{
		width = 0;
		while (width < 64)

		{
			data[(start.y + height) * size_line + (start.x + width) * 4] =
				img_data[height * line + width * 4];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 1] =
				img_data[height * line + width * 4 + 1];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 2] =
				img_data[height * line + width * 4 + 2];
			data[(start.y + height) * size_line + (start.x + width) * 4 + 3] =
				img_data[height * line + width * 4 + 3];
			width++;
		}
		height++;
	}
}

void	draw_btn(void *mlx, char *data, int size_line)
{
	t_point start;
	t_point	end;
	int		index;

	index = 0;
	start.x = 17;
	while (index < 3)
	{
		start.y = 188 + index * 81;
		end.x = start.x + 64;
		end.y = start.y + 64;
		draw_map_square(data, size_line, start, end);
		if (index == 0)
			draw_start(mlx, data, size_line, start);
		else if (index == 1)
			draw_speed_up(mlx, data, size_line, start);
		else if (index == 2)
			draw_speed_down(mlx, data, size_line, start);
		index++;
	}
}
