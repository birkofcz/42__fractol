/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/11 16:36:24 by sbenes           ###   ########.fr       */
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

/* test */
int generate_psychedelic_color(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;  // Normalize iteration count to range [0, 1]
    int red = (int)(255 * pow(1 - t, 2));           // Calculate red component
    int blue = (int)(255 * pow(t, 2));              // Calculate blue component
    int green = 0;                                  // Set green component to 0 for simplicity

    return (red << 16) | (green << 8) | blue;        // Combine color components into a single integer
}

int generate_neon_green_color(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;   // Normalize iteration count to range [0, 1]
    int red = 0;                                     // Set red component to 0 for black color
    int green = (int)(255 * pow(t, 2));              // Calculate green component
    int blue = 0;                                    // Set blue component to 0 for simplicity

    return (red << 16) | (green << 8) | blue; 
}

void	set_pixel_color(t_fractal *f, int x, int y, int color)
{
		f->img_data[x * 4 + y * WIDTH * 4] = color;
		f->img_data[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->img_data[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->img_data[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
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
            set_pixel_color(f, x, y, generate_neon_green_color(iterations));
        }
    }
    mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, 0, 0);
}