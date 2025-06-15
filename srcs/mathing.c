/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:37:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/15 22:18:39 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	scale(double to_scale, double new_min, double new_max, double old_min, double old_max)
{
	return(new_min + (new_max - new_min) * (to_scale - old_min) / (old_max - old_min));
}
