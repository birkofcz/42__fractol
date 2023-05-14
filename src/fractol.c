/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/14 11:23:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../include/fractol.h"

/* void	ft_draw_triangle(void *mlx_ptr, void *window_ptr)
{
	int x;
	int y;
	t_image triangle;

	triangle.img_ptr = mlx_new_image(mlx_ptr, 1280, 960);
	triangle.data = mlx_get_data_addr(triangle.img_ptr, &triangle.bpp, &triangle.line_size, &triangle.endian);
	
	for (y = 200; y < 400; y++)
	{
		for (x = y - 200; x < 600 - y; x++)
		{
			int position = (x * triangle.bpp / 8) + (y * triangle.line_size);
			triangle.data[position] = 0xFF;     // blue component
            triangle.data[position + 1] = 0xFF; // green component
            triangle.data[position + 2] = 0xFF;
		}
	} 
	mlx_put_image_to_window(mlx_ptr, window_ptr, triangle.img_ptr, 80, 0);
	mlx_destroy_image(mlx_ptr, triangle.img_ptr);
} */


int	main(int ac, char **av)
{
	t_fractal f;

	//(void)av;
	if (ac < 2)
		ft_help();
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
	mlx_key_hook(f.win_p, ft_key_event_handling, &f);
/* 	ft_printf("\n");
	print_fractal_state(&f); */
	//mlx_mouse_hook
	mlx_loop(f.mlx_p);
}