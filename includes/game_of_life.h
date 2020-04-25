/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 23:18:28 by jinwkim           #+#    #+#             */
/*   Updated: 2020/04/26 02:16:39 by jinwkim          ###   ########.fr       */
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

typedef struct		s_key_event
{
	t_point			old;
	int				button;
}					t_key_event;

typedef struct		s_map
{
	char			***world;
	t_camera		cam;
	t_key_event		event;
	int				limit;
	int				start;
}					t_map;

int					life_algo(t_map *map);
void				draw_screen(unsigned int **buffer, t_camera *cam);
void				put_buffer(unsigned int **buffer, t_camera *cam, char **map);
void				win_main(t_camera *cam);
void				print_plane(char **world, int limit);
int					mouse_click(int button, int x, int y, void *p);
int					mouse_event(int x, int y, void *p);
int					keyboard_event(int buttion, void *p);
#endif
