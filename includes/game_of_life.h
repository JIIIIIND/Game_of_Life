/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 23:18:28 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/22 23:19:23 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

void	life_algo(char ***world, int limit);
void	print_plane(char **world, int limit);

#endif
