/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:40:54 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/18 17:06:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* 
FT_STRLOW - making the argument lowercase for comparation purposes
 */
static char	*ft_strlow(char *str)
{
	char	*str_low;
	int		i;

	str_low = str;
	i = 0;
	while (str_low[i] != '\0')
	{
		if (str_low[i] >= 'A' && str_low[i] <= 'Z')
			str_low[i] = str_low[i] + 32;
		i++;
	}
	return (str_low);
}

/* FT_COMPARE - to compare the arguments */
static int	ft_compare_args(char *src, char *str)
{
	src = ft_strlow(src);
	if (ft_strncmp(src, str, ft_strlen(str)) == 0)
		return (0);
	return (1);
}

/* 
FT_READ_SET - reads the fractal set from av[1]. Help print
and exit if bad input.
 */
void	ft_read_set(t_fractal *f, char **av)
{
	if ((ft_atoi(av[1]) == 1) || (ft_compare_args(av[1], "mandelbrot") == 0))
		f->f_set = MANDELBROT;
	else if ((ft_atoi(av[1]) == 2) || (ft_compare_args(av[1], "julia") == 0))
		f->f_set = JULIA;
	else if ((ft_atoi(av[1]) == 3) || (ft_compare_args(av[1], "ship") == 0))
		f->f_set = BURNING_SHIP;
	else if ((ft_atoi(av[1]) == 4) || (ft_compare_args(av[1], "buddha") == 0))
		f->f_set = BUDDHABROT;
	else
	{
		ft_help();
		exit(0);
	}
}

/* 
FT_READ_JULIA_VALUES - reads the optional arguments for Julia set.
If none, sets default value.
 */
void	ft_read_julia_values(t_fractal *f, int ac, char **av)
{
	if (f->f_set != JULIA || ac == 2)
	{
		f->start_r = -0.766667;
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
FT_HANDLE_ARGUMENTS - crossroad of argument handling.
 */
void	ft_handle_arguments(t_fractal *f, int ac, char **av)
{
	if (f->f_set != JULIA && ac > 2)
		ft_help();
	else if (f->f_set == JULIA && ac > 4)
		ft_help();
	ft_read_julia_values(f, ac, av);
}
