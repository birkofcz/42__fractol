/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SET_burning_ship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:37:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:51:35 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
/* 
FT_BURNING_SHIP - 
Distortion of Mandlebrot set. Uses absolute values of complex numbers.
 */
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
