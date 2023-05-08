/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:07:52 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 14:19:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define MAX_ITER 100

static void set_pixel(t_image *img, int x, int y, int color)
{
    int position = (x * img->bpp / 8) + (y * img->line_size);
    img->data[position] = color & 0xFF;
    img->data[position + 1] = (color >> 8) & 0xFF;
    img->data[position + 2] = (color >> 16) & 0xFF;
}

int julia_set_pixel(int x, int y, double real_c, double imag_c)
{
    double real_z = (double)x / WIDTH * 3.5 - 2.5;
    double imag_z = (double)y / HEIGHT * 2.0 - 1.0;
    int iter = 0;

    while (real_z * real_z + imag_z * imag_z < 4.0 && iter < MAX_ITER)
    {
        double real_z_squared = real_z * real_z;
        double imag_z_squared = imag_z * imag_z;

        imag_z = 2 * real_z * imag_z + imag_c;
        real_z = real_z_squared - imag_z_squared + real_c;
        
        iter++;
    }

    return iter;
}

void draw_julia_set(void *mlx_ptr, void *win_ptr)
{
    t_image img;

    img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_size, &img.endian);


    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int iter = julia_set_pixel(x, y, -0.8, 0.156);
            int color = (iter == MAX_ITER) ? 0 : (iter * 255 / MAX_ITER) * 0x010101;
            set_pixel(&img, x, y, color);
        }
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
    mlx_destroy_image(mlx_ptr, img.img_ptr);
}