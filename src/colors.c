/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:30:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 15:04:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define PI 3.14159265358979323846

/* 
FT_COLOR_DEPTHSOFHELL 
using modulo operator to creates repeating patterns  with sharp transitions
 */

int	ft_color_psychadelic(int iteration)
{
    // Normalize iteration count to range [0, 1]
    //double t = (double)iteration / MAX_ITERATIONS;
    // Modulus operator creates repeating patterns with sharp transitions
    int red = (int)(255 * (iteration % 6) / 3.0);   // Red varies between 0 and 255 every 8 iterations
    int green = (int)(255 * (iteration % 16) / 15.0); // Green varies between 0 and 255 every 16 iterations
    int blue = (int)(255 * (iteration % 4) / 3.0);  // Blue varies between 0 and 255 every 4 iterations

    // Combine red, green, and blue into a single integer
    return (red << 16) | (green << 8) | blue;
}

/* 
FT_COLOR_ELECTRICGREEN
Using abs for bright colors and cos for abrupt changes and * 0.5 + 0.5 to shift
 the result of sin from [-1, 1] to [0, 1]
 */
int ft_color_onatrip(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;

    // sin function to create more abrupt changes
    // abs function to create bright colors
    // and * 0.5 + 0.5 to shift the result of sin from [-1, 1] to [0, 1]
    t = fabs(sin(t * PI * 2)) * 0.5 + 0.5;
    
    // Calculate color components
    int red = (int)(255 * (1 - cos(t * PI / 2)));  // red from [255, 0]
    int blue = (int)(255 * cos(t * PI / 2));        // blue from [0, 255]
    int green = (int)(255 * (1 - cos((t + 0.33) * PI)));  // green offset by 0.33 for color variation

    return (red << 16) | (green << 8) | blue ;
}

int ft_color_electricgreen(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;

    // sin function to create more abrupt changes
    // abs function to create bright colors
    // and * 0.5 + 0.5 to shift the result of sin from [-1, 1] to [0, 1]
    t = fabs(sin(t * PI)) * 0.5 + 0.5;
    
    // Calculate color components
    int red = (int)(255 * pow(1 - t, 3)); 
    int blue = (int)(255 * pow(t, 3));      
    int green = (int)(255 * pow(2 * fabs(t - 0.5), 0.5));  

    return (red << 16) | (green << 8) | blue ;
}

int ft_color_blueghost(int iteration)
{
    double t = (double)iteration / MAX_ITERATIONS;

    // Adjust t to highlight the structures in the Phoenix fractal
    t = pow(t, 0.5);

    // Calculate color components
    int red = (int)(255 * pow(1 - t, 3));
    int green = (int)(255 * pow(t, 0.8));
    int blue = (int)(255 * pow(t, 0.5));

    return (red << 16) | (green << 8) | blue;
}

int ft_color_blackwhite(int iteration) //this one for buddhabrot, looks nice like that
{
    double t = (double)iteration / MAX_ITERATIONS;
    
    // Calculate color components
    int intensity = (int)(255 * t);
    
    return (intensity << 16) | (intensity << 8) | intensity;
}


/* int generate_basic(int iteration)
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
} */