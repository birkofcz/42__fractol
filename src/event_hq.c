/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 15:55:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_KEY_EVENT - controls the actions on keypress. This is crossroad
for event handling defined in events.c
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
	else if (key == KEY_C || key == KEY_S)
		ft_cycle(key, f);
	else
		return (1);
	ft_layout(f);
	ft_render(f);
	return (0);
}

