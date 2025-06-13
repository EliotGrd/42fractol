/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:02 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/13 19:41:05 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	handle_key(int keycode, void *f)
{
	if (keycode == KEY_ESC)
		exit_fractol(0, f);
	else if (keycode == KEY_W || keycode == KEY_UP)
			ft_printf("up pressed\n");
	else if (keycode == KEY_A || keycode == KEY_LEFT)
			ft_printf("left pressed\n");
	else if (keycode == KEY_S || keycode == KEY_DOWN)
			ft_printf("down pressed\n");
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
			ft_printf("right pressed\n");
	else if (keycode == KEY_PLUS)
			ft_printf("plus pressed\n");
	else if (keycode == KEY_MINUS)
			ft_printf("minus pressed\n");
	(void)f;
}

void	handle_mouse_key(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	(void)f;
	if (keycode == MOUSE_WHEEL_UP)
		ft_printf("zoomed in\n");
	else if (keycode == MOUSE_WHEEL_DOWN)
			ft_printf("zoomed out\n");
}

void	handle_close(t_fractol *f) {
    (void)f;
    exit_fractol(0, f);
}

int main(void)
{
	//t_imag	img;
	t_fractol f;

	//if (check_input(fractol, ac, av) == 1)
	//	exit();
	test(1);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "fractale stylee UwU");
    //draw_fractal(&f);
	mlx_key_hook(f.win, (int (*)(int, void *))handle_key, &f);
	mlx_mouse_hook(f.win, (int (*)(int, int, int, void *))handle_mouse_key, &f);
	mlx_hook(f.win, 17, 0, (int (*)(void *))handle_close, &f);
	//initfractal();
	mlx_loop(f.mlx);
	//img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}
