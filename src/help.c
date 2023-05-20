/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:55:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:02:13 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* FT_HELP - Prints the instructions on screen. Also ends the program
as this is shown only in cases of bad input.
  */

void	ft_help(void)
{
	ft_printf("%s%s\nrun ./fractol <fractal_set> ", BOLD, GREEN);
	ft_printf("%s%s<opt:julia_param1> ", BOLD, GREEN);
	ft_printf("%s%s<opt:julia_param2>%s\n\n", BOLD, GREEN, RESET);
	ft_printf("Mandelbrot:\t'1' or 'mandelbrot'\n");
	ft_printf("Julia:\t\t'2' or 'julia'\n");
	ft_printf("Burning ship:\t'3' or 'ship'\n\n");
	ft_printf("Julia parameters are optional.\n\n");
	exit(0);
}
