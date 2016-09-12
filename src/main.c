#include "fractol.h"

int		ft_fps(clock_t start, clock_t end, t_env *e)
{
	char	fps[0xF00];

	fps[0] = '\0';
	ft_strcat(fps, "FPS = ");
	ft_putnbr((int)1000 / ((end - start) * 1000  / CLOCKS_PER_SEC));
	ft_putchar('\n');
	ft_strcat(fps, "   Type = ");
	ft_strcat(fps, e->type);
	ft_strcat(fps, "   Ite Max = ");
	ft_strcat(fps, ft_itoa(e->f->ite_max));
	ft_strcat(fps, "   Color = ");
	ft_strcat(fps, ft_itoa(e->f->pal + 1));
	mlx_string_put(e->mlx, e->win, 20, WIN_H - 20, 0xFFFFFF, fps);
	return (1);
}

int		ft_expose_hook(t_env *e)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	if (e->key || e->first)
	{
		e->first = 0;
		init_palette(e);
		ft_move(e);
		init_thread(e);
		end = clock();
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
		ft_fps(start, end, e);
	}
	return (1);
}

int		ft_motion(int x, int y, t_env *e)
{
	if (e->f->mstp && ft_strequ(e->type, "Julia") && x > 0 &&
		y > 0 && x < WIN_W && y < WIN_H)
	{
		e->first = 1;
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
		(x > (WIN_W / 2)) ? (e->f->movex += 0.1 / e->f->zoom) :
		(e->f->movex -= 0.1 / e->f->zoom);
		(y > (WIN_H / 2)) ? (e->f->movey += 0.1 / e->f->zoom) :
		(e->f->movey -= 0.1 / e->f->zoom);
	}
	else if (key == 5)
	{
		e->f->zoom /= 1.1;
		e->f->ite_max -= 1;
	}
	e->first = 1;
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
	e.first = 1;
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
