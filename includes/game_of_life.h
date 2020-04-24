/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 23:18:28 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/25 00:09:55 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_camera
{
	t_point			start;
	t_point			end;
	t_point			res;
	double			cell_size;
	void			*mlx;
	void			*win;
	unsigned int	**buffer;
}					t_camera;

typedef struct		s_map
{
	char			***world;
	t_camera		cam;
	int				limit;
}					t_map;

int					life_algo(t_map *map);
void				draw_screen(unsigned int **buffer, t_camera *cam);
void				put_buffer(unsigned int **buffer, t_camera *cam, char **map);
void				win_main(t_camera *cam);
void				print_plane(char **world, int limit);

#endif
