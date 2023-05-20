/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SET_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:07:52 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:50:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_REMARKABLE_JULIAS 
Added function to store and cycle some predefined added complex numbers,
to show some interesting shapes. Cycle is active when showing the Julia factal.
 */
int	ft_remarkable_julias(int key, t_fractal *f)
{
	double	values[7][2];

	values[0][0] = -0.766667;
	values[0][1] = -0.090000;
	values[1][0] = -0.506667;
	values[1][1] = 0.520000;
	values[2][0] = 0.403333;
	values[2][1] = 0.273333;
	values[3][0] = 0.371504;
	values[3][1] = -0.153893;
	values[4][0] = 0.386667;
	values[4][1] = 0.103333;
	values[5][0] = -0.203333;
	values[5][1] = -0.696667;
	values[6][0] = 0.18;
	values[6][1] = -0.566667;
	if (key >= KEY_1 && key <= KEY_7)
	{
		f->start_r = values[key - KEY_1][0];
		f->start_i = values[key - KEY_1][1];
	}
	else
		return (1);
	ft_render(f);
	return (0);
}

/* 
FT_JULIA-
Julia works similary to Mandelbrot.
Mandelbrot uses 0 as a starting value for zr and zi, and
adds pixel coordinates (cr and ci) every time it iterates.

Julia starts with pixel coordinates as zr and zi and adds another 
complex number (start_r and start_i) every time it iterates.
Start_r and start_i  values determine the shape Julia will take on.
If they are part of the Mandelbrot set, Julia will be a continuous
solid shape. If not, the Julia fractal will be a disconnected set 
of separate islands.

There is a basic value of complex number if not specified.
 */
int	ft_julia(t_fractal *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->start_i;
		zr = zr * zr - zi * zi + f->start_r;
		zi = tmp;
		n++;
	}
	return (n);
}
