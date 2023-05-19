struct s_buddha{
	int		x;
	int		y;
	int		i;
	int		n;
	double	pr;
	double	pi;
	double	zr;
	double	zi;
	double	zr_temp;
	long long		**buddhabrot_map;
};

void	ft_render_buddhabrot(long long **buddhabrot_map, t_fractal *f)
{
	int	i;
	int	y;

	i = 0;
	while (i++ < HEIGHT)
	{
		y = 0;
		while (y++ < WIDTH)
			ft_set_pixel_color(f, i, y, ft_set_color(f, buddhabrot_map[i][y]));
	// Don't forget to free the buddhabrot_map when you're done with it
	}
	i = 0;
	while (i++ < HEIGHT)
		free(buddhabrot_map[y]);
	free(buddhabrot_map);
}


void	ft_buddhabrot(t_fractal *f)
{
	struct s_buddha	s;

	s.buddhabrot_map = malloc(HEIGHT * sizeof(long long *));
	s.y = 0;
	while (s.y++ < HEIGHT)
		s.buddhabrot_map[s.y] = malloc(WIDTH * sizeof(long long));
	s.i = 0;
	while (s.i++ < BUDDHABROT_SAMPLING)
	{
		s.pr = (double)rand() / RAND_MAX * (f->max_r - f->min_r) + f->min_r;
		s.pi = (double)rand() / RAND_MAX * (f->max_i - f->min_i) + f->min_i;
		s.zr = 0.0;
		s.zi = 0.0;
		s.n = 0;
		while (s.n++ < BUDDHABROT_MAX_ITERATIONS)
		{
			if ((s.zr * s.zr + s.zi * s.zi) > 4.0)
				break ;
			s.zr_temp = s.zr * s.zr - s.zi * s.zi + s.pr;
			s.zi = 2 * s.zr * s.zi + s.pi;
			s.zr = s.zr_temp;
			s.x = (int)((s.zr - f->min_r) / (f->max_r - f->min_r) * WIDTH);
			s.y = (int)((s.zi - f->min_i) / (f->max_i - f->min_i) * HEIGHT);
			if (s.x >= 0 && s.x < WIDTH && s.y >= 0 && s.y < HEIGHT)
				s.buddhabrot_map[s.y][s.x]++;
		}
	}
	ft_render_buddhabrot(s.buddhabrot_map, f);
}