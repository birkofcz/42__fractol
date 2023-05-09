/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:33:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/09 14:41:32 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
	FT_CLEAN_EXIT
	exits the program clean way - no memory leaks
 */

void	ft_clean_exit(t_fractal *f)
{
	if (!f)
		exit(0);
	if (f->img_p)
		mlx_destroy_image(f->mlx_p, f->win_p);
	if (f->win_p && f->mlx_p)
		mlx_destroy_window(f->mlx_p, f->win_p);
	if (f->mlx_p)
	{
		mlx_loop_end(f->mlx_p);
		mlx_destroy_display(f->mlx_p);
		free(f->mlx_p);
	}
	exit(0);
}