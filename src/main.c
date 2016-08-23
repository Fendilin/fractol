#include "fractol.h"

int		init_palette(t_env *e)
{
	int	i;

	i = 0;
	if (e->f->pal == 0)
	{
		while (i < 256)
		{
			e->f->color[i] = 0x000055 + i;
			e->f->color[i + 256] = 0x000055 - i;
			e->f->color[i + 512] = 0x000055 * i;
			e->f->color[i + 768] = 0x000055 / (i + 1);
			i++;
		}
	}
	else if (e->f->pal == 1)
	{
		while (i < 256)
		{
			e->f->color[i] = 0xA0AA00 + i;
			e->f->color[i + 256] = 0xA0AA00 - i;
			e->f->color[i + 512] = 0xA0AA00 * i;
			e->f->color[i + 768] = 0xA0AA00 / (i + 1);
			i++;
		}
	}
	else if (e->f->pal == 2)
	{
		while (i < 256)
		{
			e->f->color[i] = 0xAA0000 + i;
			e->f->color[i + 256] = 0xAA0000 - i;
			e->f->color[i + 512] = 0xAA0000 * i;
			e->f->color[i + 768] = 0xAA0000 / (i + 1);
			i++;
		}
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

int		ft_expose_hook(t_env *e)
{
	init_palette(e);
	ft_move(e);
	if (ft_strequ(e->type, "Mandelbrot"))
		do_fract(e, ft_mandel);
	else if (ft_strequ(e->type, "Julia"))
		do_fract(e, ft_julia);
	else if (ft_strequ(e->type, "Burning_ship"))
		do_fract(e, ft_burning);
	else
		ft_usage();
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (1);
}

int		ft_motion(int x, int y, t_env *e)
{
	if (e->f->mstp && ft_strequ(e->type, "Julia") && x > 0 && y > 0 && x < WIN_W && y < WIN_H)
	{
		e->f->c_r = -0.772691322542185 + (0.00002 * x);
		e->f->c_i = 0.124281466072787 + (0.00002 * y);
	}
	return (1);
}

int		ft_mouse_hook(int key, int x, int y, t_env *e)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 4)
	{
		e->f->zoom *= 1.1;
		e->f->ite_max += 1;
		(x > (WIN_W / 2)) ? (e->f->movex += 0.1 / e->f->zoom) : (e->f->movex -= 0.1 / e->f->zoom);
		(y > (WIN_H / 2)) ? (e->f->movey += 0.1 / e->f->zoom) : (e->f->movey -= 0.1 / e->f->zoom);
	}
	else if (key == 5)
	{
		e->f->zoom /= 1.1;
		e->f->ite_max -= 1;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	e;
	t_img	img;
	t_fract	fract;

	if (argc < 2)
		ft_usage();
	e.type = ft_strdup(argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "TEST");
	img.img = mlx_new_image(e.mlx, WIN_W, WIN_H);
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.ed);
	e.img = &img;
	e.f = &fract;
	init_fract(&e);
	mlx_hook(e.win, 3, 2, ft_key_press, &e);
	mlx_hook(e.win, 2, 1, ft_key_release, &e);
	mlx_mouse_hook(e.win, ft_mouse_hook, &e);
	mlx_hook(e.win, MN, PMM,ft_motion, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	mlx_loop_hook(e.mlx, ft_expose_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
