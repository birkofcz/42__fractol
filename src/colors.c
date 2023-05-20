/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:30:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:53:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define PI 3.14159265358979323846

/* 
Color rendering function. The color generated is used to color the pixels. 
Color depending on how many iterations the pixel have. On the beginning, where 
needed, the count is bormalize between the 0 and 1 
((double)iterations / MAX_TERATIONS (100) will give the iterations number
like 59 = 0.59).

Normalized count is then used to generate RGB color, with 0 - 255 values for 
every channel. Some mathematic functions are used for that. 

RGB system - Red, Green and Blue channels, where 0 is the absence of that color 
and 255 is full presence of that color.

Final RGB color is represented as 32bit integer, where RGB channels are 
bitshifted.
 */

/* 
FT_COLOR_PSYCHADELIC
using modulo operator to create repeating patterns with sharp transitions. 
Red, green and blue varies between 0 and 255 every n interations. Return
combines red, green and blue into the single integer using bitshift.
 */

int	ft_color_psychadelic(int iteration)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(255 * (iteration % 6) / 3.0);
	green = (int)(255 * (iteration % 16) / 15.0);
	blue = (int)(255 * (iteration % 4) / 3.0);
	return ((red << 16) | (green << 8) | blue);
}

/* 
FT_COLOR_ONATRIP
The line "t = fabs(sin(t * PI * 2)) * 0.5 + 0.5;" transforms 
the value of t by creating a sinusoidal wave. In this way, 
the value of t will repeatedly change between 0 and 1,
 leading to an effect where the color changes repeatedly 
 with an increasing number of iterations.
 */
int	ft_color_onatrip(int iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / MAX_ITERATIONS;
	t = fabs(sin(t * PI * 2)) * 0.5 + 0.5;
	red = (int)(255 * (1 - cos(t * PI / 2)));
	green = (int)(255 * (1 - cos((t + 0.33) * PI)));
	blue = (int)(255 * cos(t * PI / 2));
	return ((red << 16) | (green << 8) | blue);
}

/* 
FT_COLOR_ELECTRICGREEN
The line "t = fabs(sin(t * PI)) * 0.5 + 0.5;" transforms the 
value of t by creating a sinusoidal wave. In this way, the 
value of t will repeatedly change between 0 and 1, leading 
to an effect where the color changes repeatedly with an 
increasing number of iterations.
*/
int	ft_color_electricgreen(int iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / MAX_ITERATIONS;
	t = fabs(sin(t * PI)) * 0.5 + 0.5;
	red = (int)(255 * pow(1 - t, 3));
	green = (int)(255 * pow(2 * fabs(t - 0.5), 0.5));
	blue = (int)(255 * pow(t, 3));
	return ((red << 16) | (green << 8) | blue);
}

/* 
FT_COLOR_BLUEGHOST
 */
int	ft_color_blueghost(int iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / MAX_ITERATIONS;
	t = pow(t, 0.5);
	red = (int)(255 * pow(1 - t, 3));
	green = (int)(255 * pow(t, 0.8));
	blue = (int)(255 * pow(t, 0.5));
	return ((red << 16) | (green << 8) | blue);
}

/* 
FT_COLOR_BLACKWHITE
Basic black/white spectrum. It is calculated only on values
between 0 - 255 used for twe whole 32bit int. The result will be 
absolute white, absolute black and shades of grey.
 */
int	ft_color_blackwhite(int iteration)
{
	double	t;
	int		intensity;

	t = (double)iteration / MAX_ITERATIONS;
	intensity = (int)(255 * t);
	return ((intensity << 16) | (intensity << 8) | intensity);
}
