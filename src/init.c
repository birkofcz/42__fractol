/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:40:54 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/09 15:26:03 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*	
	FT_INIT
	clean initialization for t_fractal struct.
*/

void	ft_init_fractal(t_fractal *f, int set)
{
	ft_init_mlx_win(f);
	ft_init_img(f);
	f->f_set = set;
	f->nr = 0;
	f->ni = 0;
	f->color_scheme = 0;
}

void	ft_init_mlx_win(t_fractal *f)
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
}



