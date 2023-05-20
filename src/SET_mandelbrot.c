/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SET_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:19:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:52:01 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_MANDELBROT -
Calculates Mandelbrot set, testing if the complex number (calculated before
from the pixel position) escapes to infinity (not a part of the set) or stays 
within the complex plane (is part of the set). Iterates until it escapes or hits
the MAX_ITERATIONS. Returns the number of iterations to determine color.
 */
int	ft_mandelbrot(double cr, double ci)
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
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
