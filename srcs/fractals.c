/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:03:07 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/16 22:01:02 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex z;
	int	n;

	n = 0;
	z.reel = 0;
	z.imag = 0;
	while (n <= MAX_ITER && c_abs(z) <= 2.0)
	{
		z = c_add(c_mult(z, z), c);

		n++;
	}
	return (n);
}

int	burningship(t_complex c)
{
	t_complex z;
	int	n;

	n = 0;
	z.reel = 0;
	z.imag = 0;
	while (n <= MAX_ITER && c_abs(z) <= 2.0)
	{
		z.reel = fabs(z.reel);
		z.imag = fabs(z.imag);
		z = c_add(c_mult(z, z), c);
		n++;
	}
	return (n);
}
