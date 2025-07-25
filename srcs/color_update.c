/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:03:50 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/20 23:31:13 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void update_color_table(t_fractol *f)
{
	int	i;

	i = 0;
    if (f->color_table)
        free(f->color_table);
    f->color_table = malloc(sizeof(int) * (f->c_max_iter + 1));
	if (!f->color_table)
		exit_fractol(MALLOC, f);
	while (i <= f->c_max_iter)
	{
        if (f->color_mode == 0)
            f->color_table[i] = poli_gradiant(i, f->c_max_iter);
        else if (f->color_mode == 1)
            f->color_table[i] = sin_tripy(i, f->c_max_iter);
        else if (f->color_mode == 2)
            f->color_table[i] = fire_thing(i, f->c_max_iter);
        else if (f->color_mode == 3)
            f->color_table[i] = purple_trip(i, f->c_max_iter);
        else
            f->color_table[i] = BLACK;
		i++;
    }
}
