/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:33:59 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/20 23:31:36 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Window */
# define WIDTH 1080
# define HEIGHT 1080

/* Misc */
# define MAX_ITER 50

/* Err Codes */
# define QUIT 0
# define INPUT 1
# define MALLOC 2

/* Libraries */
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* COLORS */
#define BLACK   0xFF000000

/* KEYS */
# define KEY_RED_CROSS 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_MINUS 45
# define KEY_PLUS 61
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define KEY_C 99

/* Structs */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*type;
	int		c_max_iter;
	int		color_mode;
	double	zoom;
    double	offset_x;
    double	offset_y;
	double	jr;
	double	ji;
	int		*color_table;
}			t_fractol;

typedef struct s_pixel
{
	double	x;
	double	y;
}			t_pixel;

typedef struct s_complex
{
	double	reel;
	double	imag;
}			t_complex;

/* Maths */
t_complex	c_add(t_complex a, t_complex b);
t_complex	c_mult(t_complex a, t_complex b);
int			c_abs(t_complex a);
double		scale(double to_scale, double new_min, double new_max, double old_max);

/* Init */
void		init_clear(t_fractol *f);
void		init_fractol(t_fractol *f);

/* Controller */
void		key_controller(t_fractol *f);

/* Fractals */
int			mandelbrot(t_complex c, int c_max_iter);
int			julia(t_complex c, t_complex z, int c_max_iter);
int			burningship(t_complex c, int c_max_iter);

/* Palettes */
int			poli_gradiant(int iter, int max_iter);
int			sin_tripy(int iter, int max_iter);
int			fire_thing(int iter, int max_iter);
int			purple_trip(int iter, int max_iter);

int			colorize(int nb_iter, t_fractol *f);
void		update_color_table(t_fractol *f);

void		init_image(t_fractol *f);
void		render_fractal(t_fractol *f);
void		exit_fractol(int errcode, t_fractol *f);

void		handle_close(t_fractol *f);
void		handle_key(int keycode, t_fractol *f);
void		handle_mouse_key(int keycode, int x, int y, t_fractol *f);

#endif
