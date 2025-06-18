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
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	//ft_printf("Drawing at x: %d, y: %d\n", x, y);
	*(unsigned int*)(img->addr + offset) = color;
}

/*void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}*/

static int	calc_right_fractal(t_fractol *f, t_complex *p)
{
	int nb_iter;
	t_complex c;

	nb_iter = 0;
	c.reel = p->reel;
	c.imag = p->imag;
	if (!ft_strncmp(f->type, "mandelbrot", 10))
		nb_iter = mandelbrot(c);
	else if (!ft_strncmp(f->type, "julia", 5))
	{
			c.reel = f->jr;
			c.imag = f->ji;
			nb_iter = mandelbrot(c);
	}
	else if (!ft_strncmp(f->type, "burningship", 11))
			nb_iter = burningship(c);
	return (nb_iter);
}

void	render_fractal(t_fractol *f)
{
	int		x;
	int		y;
	int		nb_iter;
	t_complex p;
	int		color;


	if (f->img.img)
	{
		mlx_destroy_image(f->mlx, f->img.img);
	}
	init_image(f);
	y = -1;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			p.reel = scale(x, -2.0, 2.0, WIDTH) + f->offset_x;
			p.imag = scale(y, -2.0, 2.0, HEIGHT) + f->offset_y;
			nb_iter = calc_right_fractal(f, &p);
			color = colorize(nb_iter);
			//ft_printf("Bits per pixel: %d\n", f->img.bits_per_pixel);
			//ft_printf("Line length: %d\n", f->img.line_length);
			my_mlx_pixel_put(&f->img, x, y, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
