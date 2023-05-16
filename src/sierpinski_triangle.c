/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:03:50 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/16 11:09:46 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_set_pixel_color(t_fractal *f, int x, int y, int color)
{
	f->img_data[x * 4 + y * WIDTH * 4] = color;
	f->img_data[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->img_data[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->img_data[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}


void draw_sierpinski_triangle(t_fractal *f, int x1, int y1, int x2, int y2, int x3, int y3, int depth)
{
    if (depth <= 0)
    {
        // Base case: Draw a simple triangle.
        ft_set_pixel_color(f, x1, y1, 0xFFFFFF);
    	ft_set_pixel_color(f, x2, y2, 0xFFFFFF);
        ft_set_pixel_color(f, x3, y3, 0xFFFFFF);
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
        draw_sierpinski_triangle(f, x1, y1, mx1, my1, mx3, my3, depth - 1);
        draw_sierpinski_triangle(f, x2, y2, mx1, my1, mx2, my2, depth - 1);
        draw_sierpinski_triangle(f, x3, y3, mx2, my2, mx3, my3, depth - 1);
    }
}

void draw_sierpinski(t_fractal *f)
{
    // Initial triangle vertices and recursion depth.
    int x1 = WIDTH / 2;
    int y1 = 50;
    int x2 = 50;
    int y2 = HEIGHT - 50;
    int x3 = WIDTH - 50;
    int y3 = HEIGHT - 50;
	int depth = 8; // Adjust this value to change the recursion depth of the Sierpinski triangle.

    // Draw the Sierpinski triangle.
    draw_sierpinski_triangle(f->img_p, x1, y1, x2, y2, x3, y3, depth);

    // Display the image on the window.
    mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, 0, 0);
    //mlx_destroy_image(f->mlx_p, f->img_p);
}