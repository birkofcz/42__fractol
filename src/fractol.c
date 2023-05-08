/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:49:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 10:16:55 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../include/fractol.h"

/* This function will create a new program instance - initialize new window */
t_window new_window(int w, int h, char *s)
{
	void *mlx;

	mlx = mlx_init();
	return ((t_window) {mlx, mlx_new_window(mlx, w, h, s), w, h});
}

int	ft_handle_exit(int key, t_window *test)
{
	if (key == KEY_ESC)
	{
		ft_printf("Keypress event: %d\n", key); // for the check, delete after
		mlx_destroy_window(test->mlx, test->window);
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
	mlx_destroy_window(test->mlx, test->window);
	exit(0);
	return (0);

}

int	main()
{
	t_window	test;
	//t_img		img;

	test = new_window(300, 300, "Test window");
	if (!test.mlx || !test.window)
		return (1);
	//img.img = mlx_new_image(test.mlx, 300, 300);
	// Writing some pixels - test
/* 	mlx_pixel_put(test.mlx, test.window, 300/2, 300/2, 0xFFFFFF);
	mlx_pixel_put(test.mlx, test.window, 300/2 + 1, 300/2, 0xFFFFFF);
	mlx_pixel_put(test.mlx, test.window, 300/2 + 2, 300/2, 0xFFFFFF);
	// Putting a string in
	mlx_string_put(test.mlx, test.window, 10, 20, 0xFFFFFF, "Hello"); */
	
	mlx_key_hook(test.window, ft_handle_exit, &test);
	mlx_mouse_hook(test.window, ft_handle_exit, &test);
	mlx_hook(test.window, 17, 0, close_window, &test);
	mlx_loop(test.mlx);
	return (0);
}