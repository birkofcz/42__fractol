/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:48:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/20 10:20:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
	FT_ATOF
	ascii to float - converts strings to floatig point int.
	Includes helping function ft_space_sign - skips spaces and updates sign.
 */

static int	ft_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = ft_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-100);
	return (nb * is_neg);
}

/* void	print_fractal_state(const t_fractal *f)
{
	ft_printf("f->mlx_p: %s\n", (f->mlx_p == NULL) ? "null" : "not null");
	ft_printf("f->win_p: %s\n", (f->win_p == NULL) ? "null" : "not null");
	ft_printf("f->img_p: %s\n", (f->img_p == NULL) ? "null" : "not null");
	ft_printf("f->img_data: %s\n", (f->img_data == NULL) ? "null" : "not null");
	ft_printf("f->f_set: %d\n", f->f_set);
	ft_printf("f->min_r: %f\n", f->min_r);
	ft_printf("f->max_r: %f\n", f->max_r);
	ft_printf("f->min_i: %f\n", f->min_i);
	ft_printf("f->max_i: %f\n", f->max_i);
	ft_printf("f->start_r: %f\n", f->start_r);
	ft_printf("f->start_i: %f\n", f->start_i);
	ft_printf("f->color_scheme: %d\n", f->color_scheme);
} */