/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:55:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 11:28:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


/* FT_HELP - Prints the instruction on screen.  */

void	ft_help()
{
	//ft_printf("\n%s[ FRACT'OL HELP ]%s\n\n", BOLD, RESET);
	ft_printf("%s%s\nrun ./fractol <fractal_set> <opt:julia_param1> <opt:julia_param2>%s\n\n", BOLD, GREEN, RESET);
	ft_printf("Mandelbrot:\t'1' or 'mandelbrot'\n");
	ft_printf("Julia:\t\t'2' or 'julia'\n");
	ft_printf("Burning ship:\t'3' or 'ship'\n");
	ft_printf("Buddhabrot:\t'4' or 'buddha'\n\n");
	ft_printf("Julia parameters are optional.\n");
	ft_printf("Unspecified, program will use default values.\n\n");
}