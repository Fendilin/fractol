#include "fractol.h"

int				do_fract(t_env *e, int (*f)(t_env *e, int x, int y))
{
	int		x;
	int		y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			f(e, x, y);
			y++;
		}
		x++;
	}
	return (1);
}

int		init_fract(t_env *e)
{
	e->f->c_r = (ft_strequ(e->type, "Julia")) ? -0.772691322542185 : 0;
	e->f->c_i = (ft_strequ(e->type, "Julia")) ? 0.124281466072787 : 0;
	e->f->z_r = 0;
	e->f->z_i = 0;
	e->f->tmp = 0;
	e->f->movex = 0;
	e->f->movey = 0;
	e->f->zoom = 1;
	e->f->ite_max = 150;
	e->key = 0;
	e->f->pal = 0;
	return (1);
}

int		ft_move(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->img);
	if (e->key & U)
		e->f->movey -= 0.1 / e->f->zoom;
	if (e->key & D)
		e->f->movey += 0.1 / e->f->zoom;
	if (e->key & L)
		e->f->movex -= 0.1 / e->f->zoom;
	if (e->key & R)
		e->f->movex += 0.1 / e->f->zoom;
	if (e->key & P)
		e->f->ite_max += 2;
	if (e->key & M && e->f->ite_max > 0)
		e->f->ite_max -= 2;
	e->img->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	return (1);
}
