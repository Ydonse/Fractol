/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:01:17 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/18 16:44:33 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_menu(t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	map->menu_ptr = mlx_new_image(map->mlx_p, 400, 200);
	map->menu_str = (unsigned char*)
		mlx_get_data_addr(map->menu_ptr, &(bpp), &(s_l), &(endian));
	map->menu_on = 1;
	map->menu_on = 1;
	display_menu(map);
}

void	display_menu(t_map *map)
{
	int i;

	i = 0;
	while (i < 400 * 200 * 4)
	{
		map->menu_str[i] = 255;
		map->menu_str[i + 1] = 255;
		map->menu_str[i + 2] = 255;
		map->menu_str[i + 3] = 50;
		i += 4;
	}
	mlx_put_image_to_window(map->mlx_p, map->win_p, map->menu_ptr, 10, 10);
	write_menu(map);
	map->menu_on = 1;
}

void	hide_menu(t_map *map)
{
	int i;

	i = 0;
	while (i < 400 * 200 * 4)
	{
		map->menu_str[i] = 0;
		map->menu_str[i + 1] = 0;
		map->menu_str[i + 2] = 0;
		i += 4;
	}
	mlx_put_image_to_window(map->mlx_p, map->win_p, map->menu_ptr, 10, 10);
	map->menu_on = 0;
	update_image(map);
}

void	write_menu(t_map *map)
{
	int value;
	int value2;

	value = 30;
	value2 = 40;
	mlx_string_put(map->mlx_p, map->win_p, value2, value, 0,
		"Change fractal      : 1 2 3");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 20, 0,
		"Zoom                : mouse wheel");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 40, 0,
		"Move Fractal        : arrows");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 60, 0,
		"Change colors       : num pad");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 80, 0,
		"Hide menu           : right click");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 100, 0,
		"Lock Julia          : L");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 120, 0,
		"Quit                : echap");
}
