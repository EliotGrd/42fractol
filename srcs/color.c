/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:37:30 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/13 19:37:34 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int colorize(int iter) {
    if (iter == MAX_ITER) return 0xFF0000;
    return BLACK - (iter * 255 / MAX_ITER) * 0x10101;
}
