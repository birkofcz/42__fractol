/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 13:55:12 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_FRACTAL_ITERATIONS -
Crossroad for iteration calculation functions for the selected fractal
 */
int	ft_fractal_iterations(t_fractal *f, double pr, double pi)
{
	int	iterations;

	iterations = 0;
	if (f->f_set == MANDELBROT)
		iterations = ft_mandelbrot(pr, pi);
	else if (f->f_set == JULIA)
		iterations = ft_julia(f, pr, pi);
	else if (f->f_set == BURNING_SHIP)
		iterations = ft_burning_ship(pr, pi);
	return (iterations);
}

/* 
FT_SET_PIXEL_COLOR -
Image is represented as a one-dimensional array of bytes, where each 
pixel  is represented by four bytes (or 32 bits) corresponding to 
the red (R), 
green (G), blue (B), and alpha (A) components of the pixel's color.

These four bytes are stored in the array one after the other, so the 
position of a particular pixel in the array is given by its (x, y) 
coordinates  in the image. The position of the first byte (R) of 
the pixel in the array  is calculated as x * 4 + y * WIDTH * 4.

x * 4: Because each pixel has four bytes, we need to shift the x index 
by 4 places for each pixel in the row. For example, if we have a pixel 
at coordinate x = 2, its R component will be at index 2 * 4 = 8 in 
the array. y * WIDTH * 4: Similarly, for each row of pixels, we need 
to add WIDTH * 4 bytes to the index. If we have a pixel at coordinate 
y = 3 in an image with a width of WIDTH = 5, its R component will be 
at index 3 * 5 * 4 = 60 in the array.

Adding these two values together, we get the total position of the R 
component of the pixel in the array.

Next, to get the positions of the other components (G, B, A) of this 
pixel, we add 1, 2, or 3 to the R component's index. That's why you 
see + 1, + 2, and + 3 in the other lines.

So, in the end, if we have a pixel at coordinates (x, y), its 
R, G, B, and A components will be at positions x * 4 + y * WIDTH 
* 4, x * 4 + y * WIDTH * 4 + 1, x * 4 + y * WIDTH * 4 + 2, and 
x * 4 + y * WIDTH * 4 + 3 in the img_data array, in this order.
 */
void	ft_set_pixel_color(t_fractal *f, int x, int y, int color)
{
	f->img_data[x * 4 + y * WIDTH * 4] = color;
	f->img_data[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->img_data[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->img_data[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

/* 
FT_SET_COLOR -
Used to set the color calculation function for chosen color_scheme.
 */
int	ft_set_color(t_fractal *f, int iterations)
{
	int	color_scheme;

	if (f->color_scheme == COLOR_ELECTRICGREEN)
		color_scheme = ft_color_electricgreen(iterations);
	else if (f->color_scheme == COLOR_ONATRIP)
		color_scheme = ft_color_onatrip(iterations);
	else if (f->color_scheme == COLOR_PSYCHADELIC)
		color_scheme = ft_color_psychadelic(iterations);
	else if (f->color_scheme == COLOR_BLUEGHOST)
		color_scheme = ft_color_blueghost(iterations);
	else if (f->color_scheme == COLOR_BW)
		color_scheme = ft_color_blackwhite(iterations);
	else
		return (1);
	return (color_scheme);
}

/* 
FT_RENDER
Renders the fractal. It takes each an every pixel in the image, 
use it as point in the complex plane and calculates (using the formula for the 
respective fractal)the number of iterations until the point is outside 
the group or the MAX_iterations is hit. Based on the number of iterations, 
it will color the pixel using the ft_set_color function with the color schemes
(they are base on the iterations number.)
pr and pi is used to create the complex number based on the pixel position.
 */
void	ft_render(t_fractal *f)
{
	int		i;
	int		j;
	double	pr;
	double	pi;
	int		iterations;

	mlx_clear_window(f->mlx_p, f->win_p);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pr = f->min_r + (double)i * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i - (double)j * (f->max_i - f->min_i) / HEIGHT;
			iterations = ft_fractal_iterations(f, pr, pi);
			ft_set_pixel_color(f, i, j, ft_set_color(f, iterations));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, 0, 0);
	ft_put_legend(f);
}
