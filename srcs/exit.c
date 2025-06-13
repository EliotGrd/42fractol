/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:13:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/13 19:42:04 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_fractol(t_fractol f)
{
	mlx_destroy_image(f.mlx, f.img.img);
	mlx_destroy_window(f.mlx, f.win);
	free(f.mlx);
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
		free_fractol(*f);
	}
	else if (errcode == INPUT)
	{
		ft_printf("Bad Input try this :\n");
	}
}
