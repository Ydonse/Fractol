/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:30:45 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/19 11:16:37 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_win(void *param)
{
	(void)param;
	exit(1);
	return (0);
}

int		read_arg(t_map *map, char *str)
{
	if (strcmp(str, "mandelbrot") == 0)
		map->mode = mandelbrot;
	else if (strcmp(str, "julia") == 0)
		map->mode = julia;
	else if (strcmp(str, "ship") == 0)
		map->mode = ship;
	else
	{
		ft_putstr("\n----------Error----------\n");
		ft_putstr("Fractol needs one of these arguments :\n");
		ft_putstr("'mandelbrot'\n'julia'\n'ship'\n");
		ft_putstr("----------Error----------\n\n");
		return (0);
	}
	return (1);
}

void	create_mlx(t_map *map)
{
	map->mlx_p = mlx_init();
	map->win_p = mlx_new_window(map->mlx_p, WIN_X, WIN_Y, "Fractol");
}

int		init(t_map *map)
{
	create_mlx(map);
	create_image(map);
	map->move = 0;
	map->code = 1;
	map->i_max = 50;
	map->lock = 0;
	map->set_v = 0;
	map->form_c = set_form_color(map->form_c, 1);
	map->origin_c = modify_color(map, map->origin_c, 1, 0);
	set_fractal_values(map);
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
	0, 0);
	create_menu(map);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
	{
		ft_putstr("\n----------Usage----------\n");
		ft_putstr("Fractol needs one of these arguments :\n");
		ft_putstr("'mandelbrot'\n'julia'\n'ship'\n");
		ft_putstr("----------Usage----------\n\n");
		return (0);
	}
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!read_arg(map, argv[1]))
		return (0);
	init(map);
	mlx_mouse_hook(map->win_p, control_mouse, (void *)(map));
	mlx_hook(map->win_p, 2, 5, control_keyboard, (void *)(map));
	mlx_hook(map->win_p, 6, 5, mouse_move, (void *)(map));
	mlx_hook(map->win_p, 17, 5, close_win, (void *)(map));
	mlx_loop(map->mlx_p);
	return (0);
}
