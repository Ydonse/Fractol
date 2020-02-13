/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:32:33 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/18 14:10:48 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_image(t_map *map)
{
	set_fractal_values(map);
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			0, 0);
	if (map->menu_on)
		display_menu(map);
}

void	destroy_image(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->destroy = 1;
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			WIN_X / 2, WIN_Y / 2);
	mlx_destroy_image(map->mlx_p, map->image_ptr);
	map->destroy = 0;
}

void	create_image(t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	map->image_ptr = mlx_new_image(map->mlx_p, WIN_X, WIN_Y);
	map->my_image_str = mlx_get_data_addr(map->image_ptr, &(bpp),
			&(s_l), &(endian));
}
