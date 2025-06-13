/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:33:59 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/12 16:40:25 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Window */
# define WIDTH 1280
# define HEIGHT 720

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
typedef struct s_imag
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_imag;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_imag	imag;
	int	is_julia;
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

#endif
