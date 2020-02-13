/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:05:34 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/18 18:34:30 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		set_color(t_color col, int r, int g, int b)
{
	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_color		modify_color(t_map *map, t_color col, int code, int i)
{
	int mult;

	mult = i * map->i_max * 255;
	if (code > 2 && code < 6)
		return (modify_color_2(map, col, code, i));
	else if (code > 5 && code < 9)
		return (modify_color_3(map, col, code, i));
	else if (code == 1)
		col = set_color(col, sin(0.3 * mult + 4) * 127 + 128, sin(0.3 *
		mult + 2) * 127 + 128, sin(0.3 * mult + 0) * 127 + 128);
	else if (code == 2)
		col = set_color(col, 123 * i / map->i_max, 14 * i / map->i_max,
			200 * i / map->i_max);
	else if (code == 9)
		col = set_color(col, sin(map->rdm.r * mult + 12) * 127 + 128, sin(map->
		rdm.g * mult + 7) * 127 + 128, sin(map->rdm.b * mult + 56) * 127 + 128);
	return (col);
}

t_color		modify_color_2(t_map *map, t_color col, int code, int i)
{
	if (code == 3)
		col = set_color(col, sin(0.2 * (i * map->i_max * 255) + 12) * 127 + 128,
		sin(0.6 * (i * map->i_max * 255) + 2) * 127 + 128,
		sin(0.1 * (i * map->i_max * 255) + 0) * 127 + 128);
	else if (code == 4)
		col = set_color(col, 0 * i / map->i_max, 255 * i / map->i_max,
		100 * i / map->i_max);
	else if (code == 5)
		col = set_color(col, 255 * i / map->i_max, 255 * i / map->i_max,
		255 * i / map->i_max);
	return (col);
}

t_color		modify_color_3(t_map *map, t_color col, int code, int i)
{
	if (code == 6)
		col = set_color(col, sin(0.3 * 255 * i / map->i_max) * 127.0 + 128.0,
		sin(0.3 * 255 * i / map->i_max + 2.0) * 127.0 + 128.0,
		sin(0.3 * 255 * i / map->i_max + 4.0) * 127.0 + 128.0);
	else if (code == 7)
		col = set_color(col, 0 * i / map->i_max, 255 * i / map->i_max,
		100 * i / map->i_max);
	else if (code == 8)
		col = set_color(col, cos(0.8 * 255 * i / map->i_max) * 127.0 + 128.0,
		255 - cos(0.8 * 255 * i / map->i_max + 2.0) * 127.0 + 128.0,
		cos(0.8 * 255 * i / map->i_max + 4.0) * 127.0 + 128.0);
	return (col);
}

t_color		set_form_color(t_color col, int code)
{
	if (code == 2)
		col = set_color(col, 229, 198, 246);
	else if (code == 4)
		col = set_color(col, 152, 253, 255);
	else if (code == 8)
		col = set_color(col, 255, 255, 255);
	else if (code == 9)
		col = set_color(col, rand() * 255 / 32767, rand() * 255 / 32767,
		rand() * 255 / 32767);
	else
		col = set_color(col, 0, 0, 0);
	return (col);
}
