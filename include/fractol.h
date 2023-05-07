/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:03:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/07 17:14:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <limits.h>
# include <math.h>

enum e_keymap
{
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
	void	*mlx;
	void	*window;
	int		height;
	int		width;
}	t_window;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_lengh;
	int		endian;
}	t_img;

# endif