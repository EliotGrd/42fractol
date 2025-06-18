/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:45:03 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/15 21:23:59 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_clear(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img.img = NULL;
	f->type = NULL;
	//f->zoom = 0;
	f->offset_x = 0;
	f->offset_y = 0;
	f->jr = 0;
	f->ji = 0;
}

void	init_image(t_fractol *f)
{
	t_img	nimg;
	nimg.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	nimg.addr = mlx_get_data_addr(nimg.img, &nimg.bits_per_pixel, &nimg.line_length, &nimg.endian);
	f->img = nimg;
}

void	init_fractol(t_fractol *f)
{
	//need to protect these
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->type);	
	//f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	//f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
}
