/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:37:37 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/15 15:02:45 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_key(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		exit_fractol(0, f);
	else if (keycode == KEY_W || keycode == KEY_UP)
			f->offset_y += 0.3;
		//	ft_printf("a");
	else if (keycode == KEY_A || keycode == KEY_LEFT)
			f->offset_x -= 0.3;
		//	ft_printf("a");
	else if (keycode == KEY_S || keycode == KEY_DOWN)
			f->offset_y -= 0.3;
		//	ft_printf("a");
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
			f->offset_x += 0.3;
		//	ft_printf("a");
	else if (keycode == KEY_PLUS)
			ft_printf("plus pressed\n");
	else if (keycode == KEY_MINUS)
			ft_printf("minus pressed\n");
	//render_fractal(f);
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

void	key_controller(t_fractol *f)
{
	mlx_key_hook(f->win, (int (*)(int, void *))handle_key, &f);
	mlx_mouse_hook(f->win, (int (*)(int, int, int, void *))handle_mouse_key, &f);
	mlx_hook(f->win, 17, 0, (int (*)(void *))handle_close, &f);

}
