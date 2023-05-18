/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 11:34:37 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractal f;

	//(void)av;
	if (ac < 2 || ac == 3)
	{
		ft_help();
		return (0);
	}
	ft_init_fractal(&f); //clean intialization
	print_fractal_state(&f);
	ft_read_set(&f, av);
	ft_handle_arguments(&f, ac, av);
	ft_printf("\n");
	print_fractal_state(&f);
	ft_init_mlx(&f);
	ft_init_image(&f);
	ft_render(&f);

	
	//print controls
	mlx_hook(f.win_p, EXIT_BUTTON, 0, ft_endgame, &f);
	mlx_mouse_hook(f.win_p, ft_mouse_event, &f);
	mlx_key_hook(f.win_p, ft_key_event, &f);
/* 	ft_printf("\n");
	print_fractal_state(&f); */
	//mlx_mouse_hook
	mlx_loop(f.mlx_p);
}