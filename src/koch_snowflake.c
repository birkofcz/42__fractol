/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_snowflake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:17:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 13:37:12 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define PI 3.14159265358979323846

void set_pixel(t_image *img, int x, int y, int color)
{
    int position = (x * img->bpp / 8) + (y * img->line_size);
    img->data[position] = color & 0xFF;
    img->data[position + 1] = (color >> 8) & 0xFF;
    img->data[position + 2] = (color >> 16) & 0xFF;
}

void draw_koch_curve(t_image *img, double x1, double y1, double x2, double y2, int depth)
{
    if (depth <= 0)
    {
        // Base case: Draw a simple line.
        //mlx_draw_line(img->img_ptr, x1, y1, x2, y2, 0xFFFFFF);
    }
    else
    {
        double dx = x2 - x1;
        double dy = y2 - y1;

        double x3 = x1 + dx / 3;
        double y3 = y1 + dy / 3;

        double x4 = x1 + 2 * dx / 3;
        double y4 = y1 + 2 * dy / 3;

        double angle = 60 * PI / 180; // 60 degrees in radians
        double x5 = x3 + (cos(angle) * (x4 - x3) - sin(angle) * (y4 - y3));
        double y5 = y3 + (sin(angle) * (x4 - x3) + cos(angle) * (y4 - y3));

        draw_koch_curve(img, x1, y1, x3, y3, depth - 1);
        draw_koch_curve(img, x3, y3, x5, y5, depth - 1);
        draw_koch_curve(img, x5, y5, x4, y4, depth - 1);
        draw_koch_curve(img, x4, y4, x2, y2, depth - 1);
    }
}

void draw_koch_snowflake(void *mlx_ptr, void *win_ptr)
{
    t_image img;

    img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_size, &img.endian);

    // Initial triangle vertices and recursion depth.
    double x1 = WIDTH / 2;
    double y1 = 50;
    double x2 = 50;
    double y2 = HEIGHT - 50;
	double x3 = WIDTH - 50;
    double y3 = HEIGHT - 50;
    int depth = 4; // Adjust this value to change the recursion depth of the Koch snowflake.

    // Draw the Koch snowflake.
    draw_koch_curve(&img, x1, y1, x2, y2, depth);
    draw_koch_curve(&img, x2, y2, x3, y3, depth);
    draw_koch_curve(&img, x3, y3, x1, y1, depth);

    // Display the image on the window.
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
    mlx_destroy_image(mlx_ptr, img.img_ptr);
}