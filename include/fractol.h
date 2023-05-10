/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/10 15:48:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <math.h>

/* Window and image dimensions */
# define WIDTH 1280
# define HEIGHT 960

/* Keymap for event handling */
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

/* Enum of available fractal sets */
enum e_fractal
{
	MANDELBROT = 1,
	JULIA = 2,
	SIERPINSKI = 3
};


/* Basic struct to hold the instance and fractal information */
typedef struct s_fractal
{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	char	*img_data;
	int		f_set;		//chosen fractal set identificator
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	start_r;	// real starting point
	double	start_i;	// imagonary starting point
	double	nr; 		//real part of complex number
	double	ni;			//imaginary part of complex number
	int		color_scheme;
	char	**arg;
}	t_fractal;

# endif

/* help.c - prints the instruction */
void	ft_help();

/* init.c - initialization of mlx, win, img and fractal info */
void	ft_init_fractal(t_fractal *f);
void	ft_init_mlx_win(t_fractal *f);
void	ft_init_img(t_fractal *f);

/* exit.c - clean exit for the program */
void	ft_clean_exit(t_fractal *f);



/* Draw fractals functions */
void draw_mandelbrot(void *mlx_ptr, void *win_ptr);
void draw_julia_set(void *mlx_ptr, void *win_ptr);
void draw_sierpinski(void *mlx_ptr, void *win_ptr);
void draw_koch_snowflake(void *mlx_ptr, void *win_ptr);
void draw_tree(void *mlx_ptr, void *win_ptr);

/* Utilities */
