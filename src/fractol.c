/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 14:04:54 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
MAIN 
Checks the arguments, print help if needed
Clean init of fractal struct
Read set
Based on the set, read arguments
Init MLX
Init window and image
Render fractal to image, put image to window.
Hook for the exit button
Hook for the keyboard actions
Hook for the mouse actions
MLX loop open - keeps the window (being close by functions
on key hooks.)
 */
int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac < 2 || ac == 3)
	{
		ft_help();
		return (0);
	}
	ft_init_fractal(&f);
	ft_read_set(&f, av);
	ft_handle_arguments(&f, ac, av);
	ft_init_mlx(&f);
	ft_init_image(&f);
	ft_render(&f);
	mlx_hook(f.win_p, EXIT_BUTTON, 0, ft_endgame, &f);
	mlx_mouse_hook(f.win_p, ft_mouse_event, &f);
	mlx_key_hook(f.win_p, ft_key_event, &f);
	mlx_loop(f.mlx_p);
}
