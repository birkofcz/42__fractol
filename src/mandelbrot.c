/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:19:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 14:03:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* TESTING THE MANDELBROT SET */

int mandelbrot_iterations(double c_re, double c_im, int max_iterations)
{
    double z_re = 0, z_im = 0;
    int iterations = 0;
    double z_re_squared, z_im_squared;

    while (iterations < max_iterations)
    {
        z_re_squared = z_re * z_re;
        z_im_squared = z_im * z_im;

        if (z_re_squared + z_im_squared > 4)
            break;

        z_im = 2 * z_re * z_im + c_im;
        z_re = z_re_squared - z_im_squared + c_re;

        iterations++;
    }

    return iterations;
}

/* void zoom_mandelbrot(t_mandelbrot *params, int x, int y, double zoom_factor)
{
    double real = params->x_min + (params->x_max - params->x_min) * x / WIDTH;
    double imag = params->y_min + (params->y_max - params->y_min) * y / HEIGHT;

    double new_width = (params->x_max - params->x_min) / zoom_factor;
    double new_height = (params->y_max - params->y_min) / zoom_factor;

    params->x_min = real - new_width / 2;
    params->x_max = real + new_width / 2;
    params->y_min = imag - new_height / 2;
    params->y_max = imag + new_height / 2;
} */

void draw_mandelbrot(void *mlx_ptr, void *win_ptr)
{
    t_image img;
    int x, y;
    int max_iterations = 200;
    double scale = 3.0 / WIDTH;

    img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_size, &img.endian);

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            double c_re = (x - WIDTH / 2) * scale - 0.5;
            double c_im = (y - HEIGHT / 2) * scale;

            int iterations = mandelbrot_iterations(c_re, c_im, max_iterations);

            int position = (x * img.bpp / 8) + (y * img.line_size);
			int color = iterations == max_iterations ? 0 : (iterations * 128 / max_iterations) & 0xFF;
            img.data[position] = color;     // blue component
            img.data[position + 1] = color; // green component
            img.data[position + 2] = color; // red component
            
        }
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
    mlx_destroy_image(mlx_ptr, img.img_ptr);
} 

