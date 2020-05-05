/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_btn.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:21:23 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/05 16:07:00 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BTN_H
# define DRAW_BTN_H

# include "game_of_life.h"
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <OpenGL/glext.h>
# include "mlx_int.h"

void	draw_btn(void *mlx, char *data, int size_line, int start_flag);
int		btn_check(int button, int x, int y, t_map *map);
#endif
