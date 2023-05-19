/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:53:55 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/19 15:05:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_CYCLE - cycles through the color schemes and fractal sets
on keypress
 */
void	ft_cycle(int key, t_fractal *f)
{
	if (key == KEY_C)
	{
		if (f->color_scheme <= 4)
			f->color_scheme += 1;
		else
			f->color_scheme = 1;
	}
	else if (key == KEY_S)
	{
		if (f->f_set <= 3)
		{
			f->f_set++;
			ft_layout(f);
		}
		else
		{
			f->f_set = 1;
			ft_layout(f);
		}
	}
}

/* 
FT_MOUSE_EVENT - event handler for mouse events. Handles zoom
and Julia set shift.
 */
/* int	ft_mouse_event(int mouse, int x, int y, t_fractal *f)
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
 */
/* 
FT_ZOOM - zooming function.
 */
void	ft_zoom(t_fractal *f, double zoom)
{
	double	center_r;
	double	center_i;
	
	ft_printf("got to zoom function\n");
	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

/* 
FT_ZOOM_MOUSE - zoom with the mouse wheel, uses mouse poiter coordinates
to zoom complex plane on that point.
 */
void	ft_zoom_mouse(t_fractal *f, double zoom, int x, int y)
{
	double	m_x;
	double	m_y;
	double	new_width;
	double	new_height;
	double	shortcut;

	shortcut = (double)(HEIGHT - y) / (double)HEIGHT;
	m_x = (double)x / (double)WIDTH * (f->max_r - f->min_r) + f->min_r;
	m_y = shortcut * (f->max_i - f->min_i) + f->min_i;
	new_width = (f->max_r - f->min_r) * zoom;
	new_height = (f->max_i - f->min_i) * zoom;
	f->min_r = m_x - new_width / 2;
	f->max_r = m_x + new_width / 2;
	f->min_i = m_y - new_height / 2;
	f->max_i = m_y + new_height / 2;
}

/* 
FT_MOVE - controls the movement - shofting the center of complex 
plane for rendering
 */
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
