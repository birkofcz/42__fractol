/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_canopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:32:10 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 13:38:15 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define PI 3.14159265358979323846

static void set_pixel(t_image *img, int x, int y, int color)
{
    int position = (x * img->bpp / 8) + (y * img->line_size);
    img->data[position] = color & 0xFF;
    img->data[position + 1] = (color >> 8) & 0xFF;
    img->data[position + 2] = (color >> 16) & 0xFF;
}

void draw_line(t_image *img, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        set_pixel(img, x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        e2 = err;

        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_tree_canopy(t_image *img, double x, double y, double angle, double length, int depth)
{
    if (depth <= 0)
    {
        return;
    }

    double new_x = x + length * cos(angle);
    double new_y = y + length * sin(angle);

    draw_line(img, x, y, new_x, new_y, 0x00FF00);

    draw_tree_canopy(img, new_x, new_y, angle - PI / 6, length * 0.67, depth - 1);
    draw_tree_canopy(img, new_x, new_y, angle + PI / 6, length * 0.67, depth - 1);
}

void draw_tree(void *mlx_ptr, void *win_ptr)
{
    t_image img;

    img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_size, &img.endian);

    double x = WIDTH / 2;
    double y = HEIGHT - 50;
    double angle = -PI / 2;
    double length = 100;
    int depth = 20;

	draw_tree_canopy(&img, x, y, angle, length, depth);

    // Display the image on the window.
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
    mlx_destroy_image(mlx_ptr, img.img_ptr);
}