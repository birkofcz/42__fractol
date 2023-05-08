/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 14:21:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../include/fractol.h"

/* This function will create a new program instance - initialize new window */
t_window ft_new_instance(int w, int h, char *s)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, s), w, h});
}

int	ft_handle_exit(int key, t_window *test)
{
	if (key == KEY_ESC)
	{
		ft_printf("Keypress event: %d\n", key); // for the check, delete after
		mlx_destroy_window(test->mlx_ptr, test->window_ptr);
		exit(0);
	}
	return (0);
}

/* Utility - to map keys and mouse clicks */
/* int keymap(int key, t_window *test)
{
	(void)test;
	ft_printf("Key pressed: %d\n", key);
	return (0);
} */


int	close_window(t_window *test)
{
	ft_printf("Close button clicked\n"); // for the check! delete after
	mlx_destroy_window(test->mlx_ptr, test->window_ptr);
	exit(0);
	return (0);

}

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


int	main()
{
	t_window	test;

	test = ft_new_instance(1280, 960, "Test window");
	if (!test.mlx_ptr || !test.window_ptr)
		return (1);
	/* creates image and draws a test triangle */
	draw_julia_set(test.mlx_ptr, test.window_ptr);
	/* Put string into the window */
	mlx_string_put(test.mlx_ptr, test.window_ptr, 10, 20, 0xFFFFFF, "Hello");
	/* Hook up the key and mouse events */
	mlx_key_hook(test.window_ptr, ft_handle_exit, &test);
	mlx_mouse_hook(test.window_ptr, ft_handle_exit, &test);
	/* Hooks up a click on exit button event (int 17) */
	mlx_hook(test.window_ptr, EXIT_BUTTON, 0, close_window, &test);
	/* Keeps the window open until closed */
	mlx_loop(test.mlx_ptr);
	return (0);
}