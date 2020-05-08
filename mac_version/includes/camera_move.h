/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:58:23 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 17:59:41 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_MOVE_H
# define CAMERA_MOVE_H

# include "game_of_life.h"

void	camera_move_up(t_map *map);
void	camera_move_down(t_map *map);
void	camera_move_left(t_map *map);
void	camera_move_right(t_map *map);

#endif
