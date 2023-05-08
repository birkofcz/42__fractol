/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:03:50 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 13:37:43 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void set_pixel(t_image *img, int x, int y, int color)
{
    int position = (x * img->bpp/ 8) + (y * img->line_size);
    img->data[position] = color & 0xFF;
    img->data[position + 1] = (color >> 8) & 0xFF;
    img->data[position + 2] = (color >> 16) & 0xFF;
}

void draw_sierpinski_triangle(t_image *img, int x1, int y1, int x2, int y2, int x3, int y3, int depth)
{
    if (depth <= 0)
    {
        // Base case: Draw a simple triangle.
        set_pixel(img, x1, y1, 0xFFFFFF);
        set_pixel(img, x2, y2, 0xFFFFFF);
        set_pixel(img, x3, y3, 0xFFFFFF);
    }
    else
    {
        // Calculate the midpoints of the triangle sides.
        int mx1 = (x1 + x2) / 2;
        int my1 = (y1 + y2) / 2;
        int mx2 = (x2 + x3) / 2;
        int my2 = (y2 + y3) / 2;
        int mx3 = (x1 + x3) / 2;
        int my3 = (y1 + y3) / 2;

        // Recursively draw the Sierpinski triangle on the three smaller triangles.
        draw_sierpinski_triangle(img, x1, y1, mx1, my1, mx3, my3, depth - 1);
        draw_sierpinski_triangle(img, x2, y2, mx1, my1, mx2, my2, depth - 1);
        draw_sierpinski_triangle(img, x3, y3, mx2, my2, mx3, my3, depth - 1);
    }
}

void draw_sierpinski(void *mlx_ptr, void *win_ptr)
{
    t_image img;

    img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_size, &img.endian);

    // Initial triangle vertices and recursion depth.
    int x1 = WIDTH / 2;
    int y1 = 50;
    int x2 = 50;
    int y2 = HEIGHT - 50;
    int x3 = WIDTH - 50;
    int y3 = HEIGHT - 50;
	int depth = 8; // Adjust this value to change the recursion depth of the Sierpinski triangle.

    // Draw the Sierpinski triangle.
    draw_sierpinski_triangle(&img, x1, y1, x2, y2, x3, y3, depth);

    // Display the image on the window.
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
    mlx_destroy_image(mlx_ptr, img.img_ptr);
}