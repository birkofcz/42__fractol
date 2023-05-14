/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/14 13:27:42 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* Mouse a keys events */

int	ft_key_event(int key, t_fractal *f)
{
	ft_printf("key pressed: %d\n", key);
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
	else
		return (1);
	ft_render(f);
	return (0);
} 

int	ft_mouse_event(int mouse, t_fractal *f)
{
	if (mouse == MOUSE_ZOOMIN)
	{
		ft_printf("mouse detected\n");
		ft_zoom(f, 0.5);
		ft_printf("edited zoom values\n");
	}
	ft_render(f);
	return (0);
}


void	ft_zoom(t_fractal *f, double zoom)
{
	double center_r;
	double center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
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
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
	else if (key == KEY_UP)
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
}