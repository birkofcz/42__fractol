/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:21:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/19 17:19:19 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Set of functions to put a legend on the screen, depending on what is being 
showed */

#include "../include/fractol.h"

static char	*ft_put_set(t_fractal *f)
{
	char	*man;
	char	*jul;
	char	*bur;

	man = "SET: Mandelbrot";
	jul = "SET: Julia";
	bur = "SET: Burning ship";
	if (f->f_set == MANDELBROT)
		return (man);
	else if (f->f_set == JULIA)
		return (jul);
	else if (f->f_set == BURNING_SHIP)
		return (bur);
	else
		return (NULL);
}

static char	*ft_put_color(t_fractal *f)
{
	char	*egreen;
	char	*trip;
	char	*psych;
	char	*bghost;
	char	*bw;

	egreen = "COLOR SCHEME: 'Electric green'";
	trip = "COLOR SCHEME: 'On a trip'";
	psych = "COLOR SCHEME: 'Psychadelic'";
	bghost = "COLOR SCHEME: 'Blue ghost'";
	bw = "COLOR SCHEME: 'Black & White'";
	if (f->color_scheme == COLOR_ELECTRICGREEN)
		return (egreen);
	else if (f->color_scheme == COLOR_ONATRIP)
		return (trip);
	else if (f->color_scheme == COLOR_PSYCHADELIC)
		return (psych);
	else if (f->color_scheme == COLOR_BLUEGHOST)
		return (bghost);
	else if (f->color_scheme == COLOR_BW)
		return (bw);
	else
		return (NULL);
}

static char	*ft_put_zoom(void)
{
	char	*zoom;

	zoom = "[ZOOM]: +, -, mouse wheel";
	return (zoom);
}

static char	*ft_put_move(void)
{
	char	*move;

	move = "[MOVE]: arrow keys";
	return (move);
}

void	ft_put_legend(t_fractal *f)
{
	mlx_string_put(f->mlx_p, f->win_p, 20, 20, 0xFFFFFF, ft_put_set(f));
	mlx_string_put(f->mlx_p, f->win_p, 20, 40, 0xFFFFFF, ft_put_color(f));
	mlx_string_put(f->mlx_p, f->win_p, 20, 80, 0xFFFFFF, ft_put_zoom());
	mlx_string_put(f->mlx_p, f->win_p, 20, 100, 0xFFFFFF, ft_put_move());
	mlx_string_put(f->mlx_p, f->win_p, 20, 120, 0xFFFFFF, "[COLOR SCHEME]: C");
	mlx_string_put(f->mlx_p, f->win_p, 20, 140, 0xFFFFFF, "[FRACTAL SET]: S");
	mlx_string_put(f->mlx_p, f->win_p, 20, 160, 0xFFFFFF, "[EXIT]: ESC");
	if (f->f_set == JULIA)
		mlx_string_put(f->mlx_p, f->win_p, 20, 200, 0xFFFFFF, "[J_SETS]: 1-7");
}
