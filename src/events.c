/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/11 16:12:46 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* Mouse a keys events */

int	ft_key_event_handling(int key, t_fractal *f)
{
	if (key == KEY_ESC)
		ft_clean_exit(f);
	
	return (0);
} 