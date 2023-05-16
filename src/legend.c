/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:21:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/16 16:47:59 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Set of functions to put a legend on the screen, depending on what is being 
showed */

#include "../include/fractol.h"


char	*ft_put_set(t_fractal *f)
{
	char *man = "SET: Mandelbrot";
	char *jul = "SET: Julia";
	char *bur = "SET: Burning ship";
	char *bud = "SET: Buddhabrot";
	

	if (f->f_set == MANDELBROT)
		return (man);
	else if (f->f_set == JULIA)
		return (jul);
	else if (f->f_set == BURNING_SHIP)
		return (bur);
	else if (f->f_set == BUDDHABROT)
		return (bud);
	else
		return (NULL);
}

void	ft_put_legend(t_fractal *f)
{
	mlx_string_put(f->mlx_p, f->win_p, 20, 20, 0xFFFFFF, ft_put_set(f));
}