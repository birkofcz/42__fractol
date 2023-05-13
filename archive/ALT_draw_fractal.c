/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ALT_draw_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:04:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/13 16:58:48 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


/* FT_RENDER_FRACTAL: crossroad function for fractal rendering */

/* void	ft_render_fractal(t_fractal *f)
{
	if (f->f_set == MANDELBROT)
		ft_draw_mandelbrot(f);
	else if (f->f_set == JULIA)
		ft_draw_julia(f);
	else if (f->f_set == SIERPINSKI)
		ft_draw_sierpinski(f);
}

void	ft_draw_mandelbrot(t_fractal *f)
{
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->max_i = -1.5;
	f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
}
 */
