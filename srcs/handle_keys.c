/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:37:37 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/20 23:31:56 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_key(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		exit_fractol(0, f);
	else if (keycode == KEY_W || keycode == KEY_UP)
			f->offset_y -= 0.4 * f->zoom;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
			f->offset_x -= 0.4 * f->zoom;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
			f->offset_y += 0.4 * f->zoom;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
			f->offset_x += 0.4 * f->zoom;
	else if (keycode == KEY_PLUS)
	{
			f->c_max_iter += 10;
			update_color_table(f);
	}
	else if (keycode == KEY_MINUS)
	{
			f->c_max_iter -= 10;
			update_color_table(f);
	}
	else if (keycode == KEY_C)
	{
			f->color_mode = (f->color_mode + 1) % 4;
			update_color_table(f);
	}
	render_fractal(f);
}

static void	zoom_at_point(int x, int y, double zoom_factor, t_fractol *f)
{
    double re;
    double im;

	re  = scale(x, -2.0 * f->zoom + f->offset_x, 2.0 * f->zoom + f->offset_x, WIDTH);
    im = scale(y, -2.0 * f->zoom + f->offset_y, 2.0 * f->zoom + f->offset_y, HEIGHT);
	f->zoom *= zoom_factor;
    f->offset_x = re - (re - f->offset_x) * zoom_factor;
    f->offset_y = im - (im - f->offset_y) * zoom_factor;
}

void	handle_close(t_fractol *f) {
    (void)f;
    exit_fractol(0, f);
}
void	handle_mouse_key(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	if (keycode == MOUSE_WHEEL_UP)
    	zoom_at_point(x, y, 0.7, f);
	else if (keycode == MOUSE_WHEEL_DOWN)
   		zoom_at_point(x, y, 1.3, f);
	render_fractal(f);
}
