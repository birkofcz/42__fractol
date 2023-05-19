/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/19 16:57:01 by sbenes           ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 1000

/* Iterations */
# define MAX_ITERATIONS 100

/* Color escape sequences */
# define BOLD "\033[1m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

/* Keymap for event handling */
enum e_keymap
{
	EXIT_BUTTON = 17,
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_C = 99,
	KEY_S = 115,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	MOUSE_LCLICK = 1,
	MOUSE_ZOOMIN = 4,
	MOUSE_ZOOMOUT = 5
};

/* Enum of available fractal sets */
enum e_fractal
{
	MANDELBROT = 1,
	JULIA = 2,
	BURNING_SHIP = 3,
	//BUDDHABROT = 4,
};

/* Enum of available color sets */
enum e_color
{
	COLOR_ELECTRICGREEN = 1,
	COLOR_ONATRIP = 2,
	COLOR_PSYCHADELIC = 3,
	COLOR_BLUEGHOST = 4,
	COLOR_BW = 5

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
	double	start_i;	// imaginary starting point
	int		color_scheme;
}	t_fractal;

/* help.c - prints the instruction */
void	ft_help(void);

/* init.c - initialization of mlx, win, img and fractal info */
void	ft_init_fractal(t_fractal *f);
void	ft_read_set(t_fractal *f, char **av);
void	ft_read_julia_values(t_fractal *f, int ac, char **av);
void	ft_handle_arguments(t_fractal *f, int ac, char **av);

void	ft_init_mlx(t_fractal *f);
void	ft_init_image(t_fractal *f);
void	ft_layout(t_fractal *f);


/* exit.c - clean exit for the program */
void	ft_clean_exit(t_fractal *f);
int		ft_endgame(t_fractal *f);

/* Draw fractals functions */
int		ft_mandelbrot(double cr, double ci);
int		ft_julia(t_fractal *f, double cr, double ci);
int		ft_remarkable_julias(int key, t_fractal *f);
void	ft_buddhabrot(t_fractal *f);
int		ft_burning_ship(double cr, double ci);
int		ft_per_mandelbrot(double cr, double ci);


/* utilities.c */
double	ft_atof(char *str);
void	print_fractal_state(const t_fractal *f);

/* render.c */
void	ft_render(t_fractal *f);

/* events.c */
int		ft_key_event(int key, t_fractal *f);
int		ft_mouse_event(int mouse, int x, int y, t_fractal *f);
void	ft_zoom(t_fractal *f, double zoom);
void	ft_zoom_mouse(t_fractal *f, double zoom, int x, int y);
void	ft_move(t_fractal *f, double distance, int key);
void	ft_cycle(int key, t_fractal *f);

/* colors.c */
int		ft_color_electricgreen(int iteration);
int		ft_color_onatrip(int iteration);
int		ft_color_psychadelic(int iteration);
int		ft_color_blueghost(int iteration);
int		ft_color_blackwhite(int iteration);

/* legend.c */
void	ft_put_legend(t_fractal *f);

int		ft_set_color(t_fractal *f, int iterations);
void	ft_set_pixel_color(t_fractal *f, int x, int y, int color);

#endif
