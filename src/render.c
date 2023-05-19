/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/19 17:03:33 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

void	ft_set_pixel_color(t_fractal *f, int x, int y, int color)
{
	f->img_data[x * 4 + y * WIDTH * 4] = color;
	f->img_data[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->img_data[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->img_data[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

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


void	ft_render(t_fractal *f)
{
	int		i;
	int		j;
	double	pr;
	double	pi;
	int		iterations;

	mlx_clear_window(f->mlx_p, f->win_p);
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			pr = f->min_r + (double)i * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i - (double)j * (f->max_i - f->min_i) / HEIGHT;
			iterations = ft_fractal_iterations(f, pr, pi);
			ft_set_pixel_color(f, i, j, ft_set_color(f, iterations));
		}
	}
	mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, 0, 0);
	ft_put_legend(f);
}

