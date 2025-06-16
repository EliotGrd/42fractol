/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:23:44 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/16 22:12:24 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	calc_right_fractal(t_fractol *f, double pr, double pi)
{
	int nb_iter;
	t_complex c;

	nb_iter = 0;
	c.reel = pr;
	c.imag = pi;
	if (f->type == "mandelbrot")
		nb_iter = mandelbrot(c);
	else if (f->type == "julia")
			nb_iter = julia(c);
	else if (f->type == "burningship")
			nb_iter = burningship(c);
	return (nb_iter);
}

int	render_fractal(t_fractol *f)
{
	int		x;
	int		y;
	int		nb_iter;
	double	pr;
	double	pi;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			pr = scale();
			pi = scale();
			nb_iter = calc_right_fractal(f, pr, pi);
		}
	}
}
