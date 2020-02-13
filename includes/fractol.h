/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:42:49 by ydonse            #+#    #+#             */
/*   Updated: 2019/04/19 09:46:40 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 800
# define WIN_Y 800
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>

typedef struct		s_color
{
	int r;
	int g;
	int b;
	int alpha;
}					t_color;

typedef struct		s_complex
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	double	z_r_square;
	double	z_i_square;
}					t_complex;

typedef enum		e_mode
{
	mandelbrot,
	julia,
	ship
}					t_mode;

typedef struct		s_map
{
	void			*mlx_p;
	void			*win_p;
	int				x;
	int				y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	t_color			origin_c;
	t_color			form_c;
	t_mode			mode;
	void			*image_ptr;
	void			*my_image_str;
	void			*menu_ptr;
	unsigned char	*menu_str;
	int				menu_on;
	short			destroy;
	double			zoom_x;
	double			zoom_y;
	int				i_max;
	int				code;
	t_color			rdm;
	short			move;
	short			lock;
	short			set_v;
}					t_map;

int					read_arg(t_map *map, char *str);
int					fill_tab(char **argv, t_map *map, int i, int fd);
int					init(t_map *map);
int					control_keyboard(int key, void *map);
void				create_mlx(t_map *map);
void				create_image(t_map *map);
void				fill_pixel(char *my_image_string, t_map *map);
void				trace_vertical(t_map *m, char *my_image);
void				check_j_line(t_map *m, int i, int j, char *my_image);
void				reset_grid(t_map *map, int i, int j);
t_color				modify_color(t_map *map, t_color col, int code, int i);
t_color				modify_color_2(t_map *map, t_color col, int code, int i);
t_color				modify_color_3(t_map *map, t_color col, int code, int i);
t_color				set_form_color(t_color col, int code);
void				destroy_image(t_map *map);
void				update_image(t_map *map);
int					percent (int start, int end, int current);
t_color				get_color_stage(int z, t_color color);
void				set_fractal_values(t_map *map);
void				browse_screen(t_map *map, int x, int y, int thread);
void				*draw_mend(void *map);
void				move_julia(t_map *m, int x, int y);
int					calculate_complex_nb(t_map *map, int x, int y, int i);
void				display_fractal (t_map *map, int x, int y, int i);
void				modify_details(t_map *m, int key);
void				get_color_code(t_map *map, int key);
void				change_mode(t_map *map, int key);
int					mouse_move(int x, int y, void *map);
int					control_mouse(int button, int x, int y, void *map);
void				apply_zoom(t_map *map, double mouse_re, double mouse_im,
					double zoom_factor);
double				interpolate(double start, double end, double interpolation);
void				move_fractal(t_map *map, int key);
void				create_menu(t_map *map);
void				hide_menu(t_map *map);
void				display_menu(t_map *map);
void				write_menu(t_map *map);
int					create_thread(t_map *map);
t_color				set_color(t_color col, int r, int g, int b);

#endif
