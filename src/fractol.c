/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/11 12:04:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../include/fractol.h"

/* 
int	ft_handle_exit(int key, t_window *test)
{
	if (key == KEY_ESC)
	{
		ft_printf("Keypress event: %d\n", key); // for the check, delete after
		mlx_destroy_window(test->mlx_ptr, test->window_ptr);
		exit(0);
	}
	return (0);
} */ 

/* Utility - to map keys and mouse clicks */
/* int keymap(int key, t_window *test)
{
	(void)test;
	ft_printf("Key pressed: %d\n", key);
	return (0);
} */


/* int	close_window(t_window *test)
{
	ft_printf("Close button clicked\n"); // for the check! delete after
	mlx_destroy_window(test->mlx_ptr, test->window_ptr);
	exit(0);
	return (0);

} */

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
	ft_read_set(&f, av);
	ft_handle_arguments(&f, ac, av);
	print_fractal_state(&f);

	/* draw_sierpinski(test.mlx_ptr, test.window_ptr);
	mlx_string_put(test.mlx_ptr, test.window_ptr, 10, 20, 0xFFFFFF, "Hello");
	mlx_key_hook(test.window_ptr, ft_handle_exit, &test);
	mlx_mouse_hook(test.window_ptr, ft_handle_exit, &test);
	mlx_hook(test.window_ptr, EXIT_BUTTON, 0, close_window, &test);
	mlx_loop(test.mlx_ptr); */
	return (0);
}