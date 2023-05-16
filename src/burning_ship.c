/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:37:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/16 16:35:51 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

/* int ft_burning_ship(double cr, double ci)
{
    int n;
    double zr;
    double zi;
    double tmp;

    zr = 0;
    zi = 0;
    n = 0;

    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break;

        // Apply absolute value to both real and imaginary parts
        zr = fabs(zr);
        zi = fabs(zi);

        // Apply the ship transformation
        tmp = zr * zr - zi * zi + cr;
        zi = fabs(2 * zr * zi) + ci;
        zr = tmp;

        n++;
    }

    return n;
} */