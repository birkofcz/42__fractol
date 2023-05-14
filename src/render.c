/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/14 15:17:49 by sbenes           ###   ########.fr       */
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
/* int generate_psychedelic_color(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;  // Normalize iteration count to range [0, 1]
    int red = (int)(255 * pow(1 - t, 2));           // Calculate red component
    int blue = (int)(255 * pow(t, 2));              // Calculate blue component
    int green = 0;                                  // Set green component to 0 for simplicity

    return (red << 16) | (green << 8) | (blue << 4) ;        // Combine color components into a single integer
} */

int ft_color_3(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;  // Normalize iteration count to range [0, 1]
    int red = (int)(200 * pow(1 - t, 2));           // Calculate red component
    int blue = (int)(255 * pow(t, 2));              // Calculate blue component
    int green = (int)(100 * pow(t, 2));              // Set green component to 0 for simplicity

    return (red << 16) | (green << 8) | (blue << 4) ;        // Combine color components into a single integer
}


int ft_color_4(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;  // Normalize iteration count to range [0, 1]
    int red = (int)(200 * pow(1 - t, 2));           // Calculate red component
    int blue = (int)(255 * pow(t, 2));              // Calculate blue component
    int green = (int)(100 * pow(t, 2));              // Set green component to 0 for simplicity

    return (red << 16) | (green << 8) | (blue << 4) ;        // Combine color components into a single integer
}

int ft_color_5(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;  // Normalize iteration count to range [0, 1]
    int red = (int)(127 * pow(1 - t, 4));           // Calculate red component
    int blue = (int)(255 * pow(t, 1));              // Calculate blue component
    int green = (int)(100 * pow(t, 2));              // Set green component to 0 for simplicity

    return (red << 16) | (green << 8) | (blue << 4) ;        // Combine color components into a single integer
}

int generate_black_white_color(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;  // Normalize iteration count to range [0, 1]
    
    int intensity = (int)(200 * t);  // Calculate intensity based on the iteration count

    return (intensity << 16) | intensity | (intensity << 4);
}

int generate_psychedelic_color(int iteration)
{
    // Calculate the value of 't' by dividing the iteration count by the maximum iterations.
    // 't' represents a value between 0 and 1 that indicates the progress of the iteration.
    double t = (double)iteration / MAX_ITERATIONS;

    // Choose the three colors for the striped scheme.
    int color1 = 0x0000FF;   // First color (e.g., deep blue) in hexadecimal RGB format
    int color2 = 0x00FF00;   // Second color (e.g., electric green) in hexadecimal RGB format
    int color3 = 0xFF0000;   // Third color (e.g., bright red) in hexadecimal RGB format

    // Interpolate between the three colors based on 't'.
    int red, green, blue;
    if (t < 1.0 / 3)
    {
        red = (1 - 3 * t) * ((color1 >> 16) & 0xFF) + (3 * t) * ((color2 >> 16) & 0xFF);
        green = (1 - 3 * t) * ((color1 >> 8) & 0xFF) + (3 * t) * ((color2 >> 8) & 0xFF);
        blue = (1 - 3 * t) * (color1 & 0xFF) + (3 * t) * (color2 & 0xFF);
    }
    else if (t < 2.0 / 3)
    {
        t -= 1.0 / 3;
        red = (1 - 3 * t) * ((color2 >> 16) & 0xFF) + (3 * t) * ((color3 >> 16) & 0xFF);
        green = (1 - 3 * t) * ((color2 >> 8) & 0xFF) + (3 * t) * ((color3 >> 8) & 0xFF);
        blue = (1 - 3 * t) * (color2 & 0xFF) + (3 * t) * (color3 & 0xFF);
    }
    else
    {
        t -= 2.0 / 3;
        red = (1 - 3 * t) * ((color3 >> 16) & 0xFF) + (3 * t) * ((color1 >> 16) & 0xFF);
        green = (1 - 3 * t) * ((color3 >> 8) & 0xFF) + (3 * t) * ((color1 >> 8) & 0xFF);
        blue = (1 - 3 * t) * (color3 & 0xFF) + (3 * t) * (color1 & 0xFF);
    }

    // Combine the red, green, and blue components to create the final color.
    return (red << 16) | (green << 8) | blue;
}

#define M_PI 3.14159265358979323846

int generate_psychedelic_color2(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;

    // sin function to create more abrupt changes
    // abs function to create bright colors
    // and * 0.5 + 0.5 to shift the result of sin from [-1, 1] to [0, 1]
    t = fabs(sin(t * M_PI)) * 0.5 + 0.5;
    
    // Calculate color components
    int red = (int)(255 * pow(1 - t, 3)); 
    int blue = (int)(255 * pow(t, 3));      
    int green = (int)(255 * pow(2 * fabs(t - 0.5), 0.5));  

    return (red << 16) | (green << 8) | blue ;
}

int generate_basic(int iteration)
{
    // Normalize iteration count to range [0, 1]
    double t = (double)iteration / MAX_ITERATIONS;

    // Calculate color components based on 't'
    // As 't' increases, red decreases and blue increases
    int red = (int)(255 * (1 - t));
    int blue = (int)(255 * t);

    // Combine red and blue to make a purple-ish color, with no green
    // Shift red 16 bits to the left and blue 8 bits to the left,
    // then combine them using bitwise OR
    return (red << 16) | blue;
}

int generate_psychedelic_color3(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;

    // sin function to create more abrupt changes
    // abs function to create bright colors
    // and * 0.5 + 0.5 to shift the result of sin from [-1, 1] to [0, 1]
    t = fabs(sin(t * M_PI * 2)) * 0.5 + 0.5;
    
    // Calculate color components
    int red = (int)(255 * (1 - cos(t * M_PI / 2)));  // red from [255, 0]
    int blue = (int)(255 * cos(t * M_PI / 2));        // blue from [0, 255]
    int green = (int)(255 * (1 - cos((t + 0.33) * M_PI)));  // green offset by 0.33 for color variation

    return (red << 16) | (green << 8) | blue ;
}

int generate_sharp_color(int iteration)
{
    // Normalize iteration count to range [0, 1]
    //double t = (double)iteration / MAX_ITERATIONS;
    // Modulus operator creates repeating patterns with sharp transitions
    int red = (int)(255 * (iteration % 6) / 3.0);   // Red varies between 0 and 255 every 8 iterations
    int green = 0;/* (int)(255 * (iteration % 16) / 15.0); */ // Green varies between 0 and 255 every 16 iterations
    int blue = 0;/* (int)(255 * (iteration % 4) / 3.0) */;  // Blue varies between 0 and 255 every 4 iterations

    // Combine red, green, and blue into a single integer
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

	ft_printf("got to render part\n");
    mlx_clear_window(f->mlx_p, f->win_p);
	ft_printf("Window cleared, going to render\n");
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
            pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;

            iterations = ft_fractal_iterations(f, pr, pi);
            set_pixel_color(f, x, y, generate_sharp_color(iterations));
        }
    }
    mlx_put_image_to_window(f->mlx_p, f->win_p, f->img_p, 0, 0);
}