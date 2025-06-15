/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:02 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/15 22:20:36 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_julia(char **av)
{
	double a;
	double b;

	a = ft_atof(av[2]);
	b = ft_atof(av[3]);
	if ((a >= -2.0 && a <= 2.0) && (b >= -2.0 && b <= 2.0))
		return (1);
	else
		return (0);
}

static int	check_input(t_fractol *f, int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		f->type = "mandelbrot";
		return (1);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5) && check_julia(av))
	{
		f->type = "julia";
		return (1);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 11))
	{
		f->type = "burningship";
		return (1);
	}
	else
	{
		exit_fractol(INPUT, f);
		return (0);
	}
}


int main(int ac, char **av)
{
	//t_imag	img;
	t_fractol f;

	(void)ac;
	(void)av;
	init_clear(&f);
	check_input(&f, ac, av);
	//test(1);
	init_fractol(&f);
    //draw_fractal(&f);
	key_controller(&f);
	mlx_loop(f.mlx);
}
