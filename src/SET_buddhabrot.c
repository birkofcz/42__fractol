/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SET_buddhabrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:55:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 13:22:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define BUDDHABROT_MAX_ITERATIONS 250 // Adjust this to increase/decrease detail
#define BUDDHABROT_SAMPLING 400000   // Adjust this to increase/decrease density

void ft_buddhabrot(t_fractal *f)
{
    int x, y, i;
    double pr, pi;
    double zr, zi, zr_temp;
    long long **buddhabrot_map;

    buddhabrot_map = malloc(HEIGHT * sizeof(long long *));
    for (y = 0; y < HEIGHT; y++)
    {
        buddhabrot_map[y] = malloc(WIDTH * sizeof(long long));
    }

    for (i = 0; i < BUDDHABROT_SAMPLING; i++)
    {
        pr = (double)rand() / RAND_MAX * (f->max_r - f->min_r) + f->min_r;
        pi = (double)rand() / RAND_MAX * (f->max_i - f->min_i) + f->min_i;

        zr = 0.0;
        zi = 0.0;

        for (int n = 0; n < BUDDHABROT_MAX_ITERATIONS; n++)
        {
            if ((zr * zr + zi * zi) > 4.0)
            {
                break;
            }

            zr_temp = zr * zr - zi * zi + pr;
            zi = 2 * zr * zi + pi;
            zr = zr_temp;

            x = (int)((zr - f->min_r) / (f->max_r - f->min_r) * WIDTH);
            y = (int)((zi - f->min_i) / (f->max_i - f->min_i) * HEIGHT);

            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            {
                buddhabrot_map[y][x]++;
            }
        }
    }

    // Now that we have the buddhabrot_map filled in, we can render it
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            ft_set_pixel_color(f, x, y, ft_set_color(f, buddhabrot_map[y][x]));
        }
    }

    // Don't forget to free the buddhabrot_map when you're done with it
    for (y = 0; y < HEIGHT; y++)
    {
        free(buddhabrot_map[y]);
    }
    free(buddhabrot_map);
}
