/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:33:59 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/16 22:01:44 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Window */
# define WIDTH 1280
# define HEIGHT 720

/* Misc */
# define MAX_ITER 100

/* Err Codes */
# define QUIT 0
# define INPUT 1

/* Libraries */
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>

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
	double zoom;
    double offset_x;
    double offset_y;
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
int	c_abs(t_complex a);
double	scale(double to_scale, double new_min, double new_max, double old_max);

/* Init */
void	init_clear(t_fractol *f);
void	init_fractol(t_fractol *f);

/* Controller */
void	key_controller(t_fractol *f);

/* Fractals */
int	mandelbrot(t_complex c);
int	julia(t_complex c);
int	burningship(t_complex c);


void	exit_fractol(int errcode, t_fractol *f);

#endif
