/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:55:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/09 15:22:23 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
	FT_HELP
	Prints the instruction on screen.
 */

void	ft_help()
{
	ft_printf("\n[ FRACT'OL HELP ]\n\n");
	ft_printf("run ./fractol <fractal_set_num> <opt:color_scheme_num> <opt:julia_param1> <opt:julia_param2>\n");
	ft_printf("\nFractal sets:\n1: Mandelbrot set\n2: Julia set\n");
	ft_printf("\nColor schemes:\n1: Black & white (default)\n\n");
}