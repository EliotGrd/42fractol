/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:02 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/12 16:36:59 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	check_input(t_fractol fractol, int ac, cahr **av)
{
	if (fractol.is_julia == 1)
	{
	}
	else
	{
		if (ac != 2)
			return (1);
		else if ()
	}
}*/

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	//t_imag	img;
	//t_fractol fractol;

	//if (check_input(fractol, ac, av) == 1)
	//	exit();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol UwU");
	//initfractal();
	//img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop(mlx);
}
