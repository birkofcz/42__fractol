/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:53:55 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:08:43 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_CYCLE - cycles through the color schemes and fractal sets
on keypress. Updates the info in struct.
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
		if (f->f_set <= 2)
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
FT_ZOOM - zooming function. Works with the complex plane, 
re-rendering the img based on what is centerpoint before 
the zoom applies. Creates the ilusion of zooming.
 */
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

/* 
FT_ZOOM_MOUSE - zoom with the mouse wheel, uses mouse poiter coordinates
to zoom complex plane on that point. Works similar to ft_zoom, but centering 
and zoomin based on mouse pointer position.
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
FT_MOVE - controls the movement - again, shifting the center of complex 
plane for re-rendering, creates illusion of movement.
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
