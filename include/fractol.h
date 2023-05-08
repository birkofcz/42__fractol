/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/08 14:02:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 960

enum e_keymap
{
	EXIT_BUTTON = 17,
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	MOUSE_LCLICK = 1,
	MOUSE_RCLICK = 3,
	MOUSE_ZOOMIN = 5,
	MOUSE_ZOOMOUT = 4
};

typedef struct s_window
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		height;
	int		width;
}	t_window;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_mandelbrot
{
    double x_min;
    double x_max;
    double y_min;
    double y_max;
    double zoom;
    int max_iterations;
} t_mandelbrot;

# endif

/* Draw fractals functions */
void draw_mandelbrot(void *mlx_ptr, void *win_ptr);
void draw_sierpinski(void *mlx_ptr, void *win_ptr);
void draw_koch_snowflake(void *mlx_ptr, void *win_ptr);
void draw_tree(void *mlx_ptr, void *win_ptr);

/* Utilities */
void zoom_mandelbrot(t_mandelbrot *params, int x, int y, double zoom_factor);


