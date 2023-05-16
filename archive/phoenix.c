/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:53:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/16 11:54:29 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int ft_phoenix(double cr, double ci, double pr, double pi)
{
    int n = 0;
    double zr = 0.0;
    double zi = 0.0;
    double zr_old = 0.0;
    double zi_old = 0.0;
    double zr_temp, zi_temp;

    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break;

        zr_temp = zr * zr - zi * zi + cr + pr * zr_old - pi * zi_old;
        zi_temp = 2 * zr * zi + ci + pr * zi_old + pi * zr_old;

        zr_old = zr;
        zi_old = zi;

        zr = zr_temp;
        zi = zi_temp;

        n++;
    }

    return n;
}
