/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:56:39 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/19 09:42:30 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fractal_values(t_map *map)
{
	if (!map->set_v)
	{
		if (map->mode == mandelbrot || map->mode == ship)
		{
			map->x1 = -2.1;
			map->x2 = 0.6;
			map->y1 = -1.2;
			map->y2 = 1.2;
		}
		else if (map->mode == julia)
		{
			map->x1 = -1;
			map->x2 = 1;
			map->y1 = -1.2;
			map->y2 = 1.2;
		}
		map->set_v = 1;
	}
	map->zoom_x = WIN_X / (map->x2 - map->x1);
	map->zoom_y = WIN_Y / (map->y2 - map->y1);
	create_thread(map);
}

void	*draw_mend(void *map)
{
	int						y;
	t_map					*m;
	static int				thread = 0;
	int						temp;
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	m = (t_map *)map;
	pthread_mutex_lock(&mutex);
	temp = thread;
	y = thread * (WIN_Y / 8);
	thread++;
	if (thread == 8)
		thread = 0;
	pthread_mutex_unlock(&mutex);
	browse_screen(m, 0, y, temp);
	pthread_exit(NULL);
}

void	browse_screen(t_map *map, int x, int y, int thread)
{
	int i;
	int tmp;

	tmp = y;
	while (x < WIN_X)
	{
		while (y < (thread + 1) * (WIN_Y / 8))
		{
			i = calculate_complex_nb(map, x, y, 0);
			display_fractal(map, x, y, i);
			y++;
		}
		x++;
		y = tmp;
	}
}

int		calculate_complex_nb(t_map *map, int x, int y, int i)
{
	t_complex com;

	com.c_r = map->mode == julia ? map->x * 0.001 : x / map->zoom_x + map->x1;
	com.c_i = map->mode == julia ? map->y * 0.001 : y / map->zoom_y + map->y1;
	if (!map->move && map->mode == julia)
	{
		com.c_r = 0.5;
		com.c_i = 0.3;
	}
	com.z_r = map->mode == julia ? x / map->zoom_x + map->x1 : 0;
	com.z_i = map->mode == julia ? y / map->zoom_y + map->y1 : 0;
	com.z_r_square = com.z_r * com.z_r;
	com.z_i_square = com.z_i * com.z_i;
	while ((com.z_r_square + com.z_i_square) < 4 && (i < map->i_max))
	{
		com.tmp = com.z_r;
		com.z_r_square = com.z_r * com.z_r;
		com.z_i_square = com.z_i * com.z_i;
		com.z_r = map->mode == ship ? fabs(com.z_r_square - com.z_i_square
			+ com.c_r) : com.z_r_square - com.z_i_square + com.c_r;
		com.z_i = map->mode == ship ? fabs(2 * com.z_i * com.tmp + com.c_i)
		: 2 * com.z_i * com.tmp + com.c_i;
		i++;
	}
	return (i);
}

void	display_fractal(t_map *map, int x, int y, int i)
{
	int		coo;
	char	*image;
	t_color	color;

	image = (char *)map->my_image_str;
	coo = (4 * x) + (4 * WIN_X * y);
	if (i == map->i_max)
	{
		image[coo] = map->form_c.r;
		image[coo + 1] = map->form_c.g;
		image[coo + 2] = map->form_c.b;
	}
	else
	{
		color = modify_color(map, map->origin_c, map->code, i);
		image[coo] = color.r;
		image[coo + 1] = color.g;
		image[coo + 2] = color.b;
	}
}
