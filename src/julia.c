/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:07:52 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/11 16:31:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_julia_shift(int x, int y, t_fractal *f)
{
	f->start_r = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->start_i = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	ft_render(f);
	return (0);
}

int	ft_julia(t_fractal *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->start_i;
		zr = zr * zr - zi * zi + f->start_r;
		zi = tmp;
		n++;
	}
	return (n);
}