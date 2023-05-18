/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 11:50:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_KEY_EVENT - controls the actions on keypress.
*/

int	ft_key_event(int key, t_fractal *f)
{
	if (key == KEY_ESC)
		ft_clean_exit(f);
	else if (key == KEY_PLUS)
		ft_zoom(f, 0.5);
	else if (key == KEY_MINUS)
		ft_zoom(f, 2);
	else if (key == KEY_UP)
		ft_move(f, 0.2, KEY_UP);
	else if (key == KEY_DOWN)
		ft_move(f, 0.2, KEY_DOWN);
	else if (key == KEY_LEFT)
		ft_move(f, 0.2, KEY_LEFT);
	else if (key == KEY_RIGHT)
		ft_move(f, 0.2, KEY_RIGHT);
	else if (key == KEY_C)
	{
		if (f->color_scheme <= 4)
			f->color_scheme += 1;
		else
			f->color_scheme = 1;
	}
	else
		return (1);
	ft_render(f);
	return (0);
}

/* 
FT_KEY_EVENT - controls the actions on mouse events.
*/

int	ft_mouse_event(int mouse, int x, int y, t_fractal *f)
{
	if (mouse == MOUSE_ZOOMIN)
		ft_zoom_mouse(f, 0.5, x, y);
	else if (mouse == MOUSE_ZOOMOUT)
		ft_zoom(f, 2);
	else if (mouse == MOUSE_LCLICK)
	{
		if (f->f_set == JULIA)
			ft_julia_shift(x, y, f);
	}
	else 
		return (1);
	ft_render(f);
	return (0);
}

void	ft_zoom(t_fractal *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

void	ft_zoom_mouse(t_fractal *f, double zoom, int x, int y)
{
	double mouseX_scaled = (double)x / (double)WIDTH * (f->max_r - f->min_r) + f->min_r;
	double mouseY_scaled = (double)(HEIGHT - y) / (double)HEIGHT * (f->max_i - f->min_i) + f->min_i;

	double new_width = (f->max_r - f->min_r) * zoom;
	double new_height = (f->max_i - f->min_i) * zoom;

	f->min_r = mouseX_scaled - new_width / 2;
	f->max_r = mouseX_scaled + new_width / 2;
	f->min_i = mouseY_scaled - new_height / 2;
	f->max_i = mouseY_scaled + new_height / 2;
}

void	ft_move(t_fractal *f, double distance, int key)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (key == KEY_RIGHT)
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (key == KEY_LEFT)
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (key == KEY_DOWN)
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (key == KEY_UP)
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}