/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_btn.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:21:23 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 17:05:57 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BTN_H
# define DRAW_BTN_H

# include "game_of_life.h"

typedef struct	s_ui
{
	char		*data;
	int			size_line;
	char		*img_data;
	int			line;
}				t_ui;

void	draw_btn(void *mlx, char *data, int size_line, int start_flag);
int		btn_check(int button, int x, int y, t_map *map);
#endif
