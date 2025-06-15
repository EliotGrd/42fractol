/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:13:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/15 21:10:28 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_fractol(t_fractol *f)
{
	if (f->img.img && f->mlx)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->mlx && f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	ft_printf("Program terminated successfully :) ");
	exit(0);
}

void	test(int i)
{
	ft_printf("%d", i);
}

void	exit_fractol(int errcode, t_fractol *f)
{
	if (errcode == QUIT)
	{
		free_fractol(f);
	}
	else if (errcode == INPUT)
	{
		ft_printf("Bad Input try this :\n    ./fractol mandelbrot\n    ./fractol julia <a> <b> (where a and b included between -2.0 et 2.0)\n    ./fractol burningship");
		exit(0);
	}
}
