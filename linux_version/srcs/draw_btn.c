/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_btn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:10:05 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 20:00:50 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "game_of_life.h"
#include "draw_ui.h"
#include "draw_btn.h"

void	draw_image(t_ui *ui, t_point start)
{
	int		width;
	int		height;
	char	*data;
	char	*img_data;

	height = 0;
	data = ui->data;
	img_data = ui->img_data;
	while (height < 64)
	{
		width = 0;
		while (width < 64)
		{
			data[(start.y + height) * ui->size_line + (start.x + width) * 4] =
				img_data[height * ui->line + width * 4];
			data[(start.y + height) * ui->size_line + (start.x + width) * 4 + 1] =
				img_data[height * ui->line + width * 4 + 1];
			data[(start.y + height) * ui->size_line + (start.x + width) * 4 + 2] =
				img_data[height * ui->line + width * 4 + 2];
			data[(start.y + height) * ui->size_line + (start.x + width) * 4 + 3] =
				img_data[height * ui->line + width * 4 + 3];
			width++;
		}
		height++;
	}
}

void	put_image(void *mlx, t_ui *ui_data, char *path, t_point start)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	ui_data->img_data = mlx_get_data_addr(img, &width, &(ui_data->line), &height);
	draw_image(ui_data, start);
	mlx_destroy_image(mlx, img);
	ui_data->img_data = 0;
	ui_data->line = 0;
}

void	draw_btn(void *mlx, char *data, int size_line, int start_flag)
{
	t_point start;
	t_point	end;
	int		index;
	t_ui	ui_data;

	index = 0;
	start.x = 17;
	ui_data.data = data;
	ui_data.size_line = size_line;
	while (index < 4)
	{
		start.y = 188 + index * 80;
		end.x = start.x + 63;
		end.y = start.y + 63;
		draw_map_square(data, size_line, start, end);
		if ((start_flag == 0) && (index == 0))
			put_image(mlx, &ui_data, "resource/start.xpm", start);
		else if ((start_flag == 1) && (index == 0))
			put_image(mlx, &ui_data, "resource/pause.xpm", start);
		else if (index == 1)
			put_image(mlx, &ui_data, "resource/speed_up.xpm", start);
		else if (index == 2)
			put_image(mlx, &ui_data, "resource/speed_down.xpm", start);
		else if (index == 3)
			put_image(mlx, &ui_data, "resource/save_load.xpm", start);
		index++;
	}
}
