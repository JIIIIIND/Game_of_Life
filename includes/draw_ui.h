/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:52:04 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/04 19:48:16 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UI_H
# define DRAW_UI_H

void	draw_panel(t_camera *cam, int limit, int start_flag);
void	draw_map_square(char *data, int size_line, t_point start, t_point end);
#endif
