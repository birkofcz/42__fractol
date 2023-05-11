/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:40:54 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/11 14:39:29 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


/* 
	FT_READ_SET
	reads the fractal set from av[1]. Help print
	and exit if bad input.
 */
void	ft_read_set(t_fractal *f, char **av)
{
	if (ft_atoi(av[1]) == 1)
		f->f_set = MANDELBROT;
	else if (ft_atoi(av[1]) == 2)
		f->f_set = JULIA;
	else if (ft_atoi(av[1]) == 3)
		f->f_set = SIERPINSKI;
	else
	{
		ft_help();
		exit(0);
	}
}

/* 
	FT_READ_JULIA_VALUES	
	Reads the optional arguments for Julia set.
	If none, sets default value.
 */
void	ft_read_julia_values(t_fractal *f, int ac, char **av)
{
	if (f->f_set != JULIA || ac == 2)
	{
		f->start_r = -0.766667; //some default values? Take a look on it!
		f->start_i = -0.090000;
		return ;
	}
	if (ac == 3)
		ft_help();
	if (!ft_strchr(av[2], '.'))
		ft_help();
	if (!ft_strchr(av[3], '.'))
		ft_help();
	f->start_r = ft_atof(av[2]);
	f->start_i = ft_atof(av[3]);
	if (f->start_r >= 2.0 || f->start_r <= -2.0)
		ft_help();
	if (f->start_i >= 2.0 || f->start_i <= -2.0)
		ft_help();
}

/* 
	FT_HANDLE_ARGUMENTS
	Crossroad of argument handling.
 */
void	ft_handle_arguments(t_fractal *f, int ac, char **av)
{
	ft_read_set(f, av);
	if (f->f_set != JULIA && ac > 2)
		ft_help();
	else if (f->f_set == JULIA && ac > 4) 
		ft_help();
	ft_read_julia_values(f, ac, av);
}

/* void	ft_init_mlx_win(t_fractal *f)
{
	f->mlx_p = mlx_init();
	if (!f->mlx_p)
		ft_clean_exit(f); // sweep_clean fucntion tbd.
	f->win_p = mlx_new_window(f->mlx_p, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win_p)
		ft_clean_exit(f); 
}

void	ft_init_img(t_fractal *f)
{
	int	bpp;
	int line_size;
	int endian;
	char *data;

	f->img_p = mlx_new_image(f->mlx_p, WIDTH, HEIGHT);
	if (!f->img_p)
		ft_clean_exit(f);
	data = mlx_get_data_addr(f->img_p, &bpp, &line_size, &endian);
	f->img_data = data;
} */



