/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:18:10 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/18 18:34:37 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	modify_details(t_map *m, int key)
{
	if (key == 69 || key == 24)
	{
		if (m->i_max < 500)
			m->i_max += 1;
		update_image(m);
	}
	else if (key == 78 || key == 27)
	{
		if (m->i_max > 1)
			m->i_max -= 1;
		update_image(m);
	}
}

void	get_color_code(t_map *map, int key)
{
	if (key == 83)
		map->code = 1;
	else if (key == 84)
		map->code = 2;
	else if (key == 85)
		map->code = 3;
	else if (key == 86)
		map->code = 4;
	else if (key == 87)
		map->code = 5;
	else if (key == 88)
		map->code = 6;
	else if (key == 89)
		map->code = 7;
	else if (key == 91)
		map->code = 8;
	else if (key == 92)
		map->code = 9;
	map->form_c = set_form_color(map->form_c, map->code);
}

void	change_mode(t_map *map, int key)
{
	if (key == 18)
	{
		map->mode = mandelbrot;
		map->i_max = 50;
	}
	else if (key == 19)
	{
		map->mode = julia;
		map->i_max = 50;
	}
	else if (key == 20)
	{
		map->i_max = 65;
		map->mode = ship;
	}
	map->set_v = 0;
	update_image(map);
}

void	move_julia(t_map *m, int x, int y)
{
	m->move = 1;
	m->x = x;
	m->y = y;
	update_image(m);
}

void	move_fractal(t_map *map, int key)
{
	if (key == 126)
	{
		map->y1 += 30 / map->zoom_y;
		map->y2 += 30 / map->zoom_y;
	}
	else if (key == 125)
	{
		map->y1 -= 30 / map->zoom_y;
		map->y2 -= 30 / map->zoom_y;
	}
	else if (key == 123)
	{
		map->x1 += 30 / map->zoom_x;
		map->x2 += 30 / map->zoom_x;
	}
	else if (key == 124)
	{
		map->x1 -= 30 / map->zoom_x;
		map->x2 -= 30 / map->zoom_x;
	}
	update_image(map);
}
