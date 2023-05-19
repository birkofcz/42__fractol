/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:11 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/19 15:04:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*	
	FT_INIT_FRACTAL	
	clean initialization for t_fractal struct.
*/
void	ft_init_fractal(t_fractal *f)
{
	f->mlx_p = NULL;
	f->win_p = NULL;
	f->img_p = NULL;
	f->img_data = NULL;
	f->f_set = 0;		//chosen fractal set identificator
	f->min_r = 0;
	f->max_r= 0;
	f->min_i = 0;
	f->max_i = 0;
	f->start_r = 0;
	f->start_i = 0;
	f->color_scheme = 1;
}

void	ft_layout(t_fractal *f)
{

	if (f->f_set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	ft_init_image(t_fractal *f)
{
	int		bpp;
	int		line_size;
	int		endian;
	char	*tmp;

	f->img_p = mlx_new_image(f->mlx_p, WIDTH, HEIGHT);
	if (!(f->img_p))
		ft_clean_exit(f);
	tmp = mlx_get_data_addr(f->img_p, &bpp, &line_size, &endian);
	f->img_data = tmp;
}

void	ft_clean_img(t_fractal *f)
{
	if (f->mlx_p && f->img_p)
		mlx_destroy_image(f->mlx_p, f->img_p);
	if (f->img_data)
		f->img_data = NULL;
	ft_init_image(f);
}

void	ft_init_mlx(t_fractal *f)
{
	f->mlx_p = mlx_init();
	if (!f->mlx_p)
		ft_clean_exit(f);
	f->win_p = mlx_new_window(f->mlx_p, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win_p)
		ft_clean_exit(f);
	ft_layout(f);
}