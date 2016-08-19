#include "fractol.h"

int		ft_newton(t_env *e, int x, int y)
{
	int		i;

	i = 0;
	e->f->c_r = 1.5 * (x - WIN_W / 2) / (e->f->zoom * WIN_W) + e->f->movex;
	e->f->c_i = (y - WIN_H / 2) / (e->f->zoom * WIN_H) + e->f->movey;
	while (i < e->f->ite_max)
	{
		e->f->z_r = e->f->c_r * e->f->c_r;
		e->f->z_i = e->f->c_i * e->f->c_i;
		e->f->newton = 3.0 * ((e->f->z_r - e->f->z_i) * (e->f->z_r - e->f->z_i)
+ 4.0 * e->f->z_r * e->f->z_i);
		if (e->f->newton == 0.0)
			e->f->newton = 0.000001;
		e->f->tmp = e->f->c_r;
		e->f->c_r = (2.0 / 3.0) * e->f->c_r + (e->f->z_r - e->f->z_i) /
e->f->newton;
		e->f->c_i = (2.0 / 3.0) * e->f->c_i - 2.0 * e->f->tmp * e->f->c_i /
e->f->newton;
		i++;
	}
	ft_put_pixel_to_img(e->f->c_r * 256, e, x, y);
	return (1);
}

int		ft_julia(t_env *e, int x, int y)
{
	int		i;

	e->f->z_r = 2 * (x - WIN_W / 2) / (0.5 * e->f->zoom * WIN_W) + e->f->movex;
	e->f->z_i = 1.1 * (y - WIN_H / 2) / (0.5 * e->f->zoom * WIN_H) + e->f->movey;
	i = 0;
	while ( i < e->f->ite_max && ((e->f->z_r * e->f->z_r) + 
			(e->f->z_i * e->f->z_i)) < 4)
	{
		e->f->tmp = e->f->z_r;
		e->f->z_r = (e->f->z_r * e->f->z_r) - (e->f->z_i * e->f->z_i) + e->f->c_r;
		e->f->z_i = (2 * e->f->z_i * e->f->tmp) + e->f->c_i;
		i++;
	}
	if (i == e->f->ite_max)
		ft_put_pixel_to_img(0x000000, e, x, y);
	else
	{
		i -= log(log((e->f->z_r * e->f->z_r) + (e->f->z_i * e->f->z_i))) / log(2);
		ft_put_pixel_to_img(e->f->color[i * (N_COLOR - 1) / e->f->ite_max], e, x, y);
	}
	return (1);
}

int		ft_mandel(t_env *e, int x, int y)
{
	int		i;

	e->f->c_r = 2 * (x - WIN_W / 2) / (0.5 * e->f->zoom * WIN_W) + e->f->movex;
	e->f->c_i = 1.1 * (y - WIN_H / 2) / (0.5 * e->f->zoom * WIN_H) + e->f->movey;
	e->f->z_r = 0;
	e->f->z_i = 0;
	i = 0;
	while (i < e->f->ite_max && ((e->f->z_r * e->f->z_r) + (e->f->z_i *
e->f->z_i)) < 4)
	{
		e->f->tmp = e->f->z_r;
		e->f->z_r = (e->f->z_r * e->f->z_r) - (e->f->z_i * e->f->z_i) + e->f->c_r;
		e->f->z_i = (2 * e->f->z_i * e->f->tmp) + e->f->c_i;
		i++;
	}
	if (i == e->f->ite_max)
		ft_put_pixel_to_img(0x000000, e, x, y);
	else
		ft_put_pixel_to_img(e->f->color[i * ((3 * 256) - 1) / e->f->ite_max], e, x, y);
	return (1);
}
