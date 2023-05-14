/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/14 16:23:00 by sbenes           ###   ########.fr       */
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
	/*else if (f->set == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	else if (f->set == TRICORN)
		nb_iter = tricorn(pr, pi);
	else if (f->set == MANDELBOX)
		nb_iter = mandelbox(f, pr, pi); */
	return (iterations);
}

void	ft_set_pixel_color(t_fractal *f, int x, int y, int color)
{
	f->img_data[x * 4 + y * WIDTH * 4] = color;
	f->img_data[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->img_data[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->img_data[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}


int	ft_set_color(t_fractal *f, int interations)
{
	int color_scheme;

	if (f->color_scheme == COLOR_ELECTRICGREEN)
		color_scheme = ft_color_electricgreen(interations);
	else if (f->color_scheme == COLOR_PSYCHADELIC)
		color_scheme = ft_color_psychadelic(interations);
	else if (f->color_scheme == COLOR_DEPTHSOFHELL)
		color_scheme = ft_color_depthsofhell(interations);
	else
		return (1);
	return (color_scheme);
}


void ft_render(t_fractal *f)
{
    int x;
    int y;
    double pr;
    double pi;
    int iterations;

    mlx_clear_window(f->mlx_p, f->win_p);
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
            pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;

            iterations = ft_fractal_iterations(f, pr, pi);
        	ft_set_pixel_color(f, x, y, ft_set_color(f, iterations));
        }
    }
    mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, 0, 0);
	ft_put_legend(f);
}

